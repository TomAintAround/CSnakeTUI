#include <ncurses.h>

void drawBorders(const int rows, const int cols) {
	move(0, 0);
	for (int _ = 0; _ < cols; _++) printw("█");

	move(rows - 1, 0);
	for (int _ = 0; _ < cols; _++) printw("█");

	for (int i = 1; i < rows - 1; i++) {
		mvprintw(i, 0, "█");
		mvprintw(i, cols - 1, "█");
	}
}

void drawMap(const int rows, const int cols) {
	drawBorders(rows, cols);
}
