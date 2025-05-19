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
	curs_set(0);
	noecho();
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
	drawMap(rows, cols);

	double frameDuration = MEDIUM_MODE;
	clock_t elapsedTime = clock();
	int dx = 1, dy = 0;
	while (!gameLost(&snake, rows - 1, cols - 1)) {
		translateInput(&dx, &dy);
		if ((double)(clock() - elapsedTime) / CLOCKS_PER_SEC < frameDuration) {
			continue;
		}

		snakePart_t* part = snake;
		move(initY, initX - 10);
		while (part != NULL) {
			printw("%d,%d ", part->x, part->y);
			part = part->next;
		}
		printw("\n");
		part = snake;

		moveSnake(&snake, dx, dy);
		drawMap(rows, cols);
		elapsedTime = clock();
	}
	nodelay(stdscr, FALSE);
	move(initY, initX - 10);
	addstr("Game Over\n");
	drawMap(rows, cols);
	getch();

	endwin();
	return 0;
}
