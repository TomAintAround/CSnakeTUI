#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>
#include "common.h"
#include "main.h"
#include "snake.h"
#include "ui.h"

bool close(const double number1, const double number2) {
	if (fabs(number1 - number2) < 0.0000000001) return true;
	return false;
}

void translateInput(int* dx, int* dy) {
	double angles[4] = { -PI / 2, -PI, PI / 2, 0 };
	double angle = angles[0];
	int key = getch();
	if (key == ERR) return;
	if (key == 'w' || key == 'W' || key == KEY_UP) {
		angle = angles[0];
	} else if (key == 'a' || key == 'A' || key == KEY_LEFT) {
		angle = angles[1];
	} else if (key == 's' || key == 'S' || key == KEY_DOWN) {
		angle = angles[2];
	} else if (key == 'd' || key == 'D' || key == KEY_RIGHT) {
		angle = angles[3];
	}

	// To avoid 180º turns
	if (!close(*dx, -cos(angle)) || !close(*dy, -sin(angle))) {
		*dx = cos(angle);
		*dy = sin(angle);
	}
}

void placeApple(snakePart_t** snake, apple_t* apple, const int rows, const int cols) {
	srand(time(NULL));
	apple->x = rand() % (cols - 2) + 1;
	apple->y = rand() % (rows - 2) + 1;

	snakePart_t* part = *snake;
	while (part != NULL) {
		if (part->x == apple->x && part->y == apple->y) {
			placeApple(snake, apple, rows, cols);
			return;
		}
		part = part->next;
	}
}

int main() {
	setlocale(LC_ALL, "");
	initscr();
	if (has_colors() == FALSE) {
		endwin();
		error("Your terminal doesn't support colors.\n");
	}
	curs_set(0);
	noecho();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	keypad(stdscr, TRUE);
	timeout(0);
	nodelay(stdscr, TRUE);
	int rows, cols;
	getmaxyx(stdscr, rows, cols);

	snakePart_t* snake;
	initSnake(&snake);
	int initY = rows / 2;
	int initX = cols / 2;
	for (int i = INIT_NUM - 1; i >= 0; i--) {
		insertPart(&snake, initX - i, initY);
	}
	apple_t apple;
	placeApple(&snake, &apple, rows, cols);
	drawMap(&snake, &apple, rows, cols);

	double frameDuration = MEDIUM_MODE;
	clock_t elapsedTime = clock();
	int dx = 1, dy = 0;
	while (!gameLost(&snake, rows - 1, cols - 1)) {
		translateInput(&dx, &dy);
		if ((double)(clock() - elapsedTime) / CLOCKS_PER_SEC < frameDuration) {
			continue;
		}

		moveSnake(&snake, dx, dy);
		drawMap(&snake, &apple, rows, cols);
		elapsedTime = clock();
	}
	cleanSnake(&snake);
	drawMap(&snake, &apple, rows, cols);
	nodelay(stdscr, FALSE);
	move(initY, initX - 6);
	attron(COLOR_PAIR(3));
	addstr("Game Over\n");
	attroff(COLOR_PAIR(3));
	drawBorders(rows, cols);
	getch();

	endwin();
	return 0;
}
