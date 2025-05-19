#include <ncurses.h>
#include <stdbool.h>
#include "snake.h"

void drawBorders(const int rows, const int cols) {
	attron(COLOR_PAIR(1));

	move(0, 0);
	for (int _ = 0; _ < cols; _++) printw("█");

	move(rows - 1, 0);
	for (int _ = 0; _ < cols; _++) printw("█");

	for (int i = 1; i < rows - 1; i++) {
		mvprintw(i, 0, "█");
		mvprintw(i, cols - 1, "█");
	}

	attroff(COLOR_PAIR(1));
}

bool isSnake(snakePart_t** snake, int row, int col) {
	snakePart_t* part = *snake;
	while (part != NULL) {
		if (part->y == row && part->x == col) return true;
		part = part->next;
	}
	return false;
}

void drawSnake(snakePart_t** snake, const int rows, const int cols) {
	for (int row = 1; row < rows - 1; row++) {
		for (int col = 1; col < cols - 1; col++) {
			if (isSnake(snake, row, col)) {
				attron(COLOR_PAIR(2));
				mvprintw(row, col, "█");
				attroff(COLOR_PAIR(2));
			} else {
				attron(COLOR_PAIR(1));
				mvprintw(row, col, " ");
				attroff(COLOR_PAIR(1));
			}
		}
	}
}

void drawMap(snakePart_t** snake, const int rows, const int cols) {
	drawSnake(snake, rows, cols);
	drawBorders(rows, cols);
}
