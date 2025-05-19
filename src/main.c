#include <stdbool.h>
#include <time.h>
#include <ncurses.h>
#include <locale.h>
#include "snake.h"
#include "common.h"
#include "ui.h"

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
	drawMap(&snake, rows, cols);

	double frameDuration = MEDIUM_MODE;
	clock_t elapsedTime = clock();
	int dx = 1, dy = 0;
	while (!gameLost(&snake, rows - 1, cols - 1)) {
		translateInput(&dx, &dy);
		if ((double)(clock() - elapsedTime) / CLOCKS_PER_SEC < frameDuration) {
			continue;
		}

		moveSnake(&snake, dx, dy);
		drawMap(&snake, rows, cols);
		elapsedTime = clock();
	}
	cleanSnake(&snake);
	drawMap(&snake, rows, cols);
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
