#include <stdlib.h>
#include <stdbool.h>
#include "snake.h"
#include "common.h"

void initSnake(snakePart_t** snake) {
	*snake = NULL;
}

void insertPart(snakePart_t** snake, const int x, const int y) {
	snakePart_t* part = (snakePart_t*)malloc(sizeof(snakePart_t));
	if (part == NULL) {
		error("A snake part wasn't successfully allocated. This is a rare "
			  "occasion and is no one's fault.\n");
	}
	part->x = x;
	part->y = y;
	part->next = NULL;
	part->next = *snake;
	*snake = part;
}

void moveSnake(snakePart_t** snake, int dx, int dy) {
	snakePart_t* part = *snake;
	int nextDX, nextDY;
	while (part != NULL) {
		if (part->next != NULL) {
			nextDX = part->x - part->next->x;
			nextDY = part->y - part->next->y;
		}
		part->x += dx;
		part->y += dy;
		dx = nextDX;
		dy = nextDY;
		part = part->next;
	}
}

void cleanSnake(snakePart_t** snake) {
	snakePart_t* part = *snake;
	while (part != NULL) {
		*snake = part->next;
		free(part);
	}
	initSnake(snake);
}

bool gameLost(snakePart_t** snake, const int maxRow, const int maxCol) {
	if ((*snake)->y < 1 || (*snake)->y > maxRow - 1) return true;
	if ((*snake)->x < 1 || (*snake)->x > maxCol - 1) return true;

	snakePart_t* part = (*snake)->next;
	while (part != NULL) {
		if ((*snake)->x == part->x && (*snake)->y == part->y) return true;
		part = part->next;
	}

	return false;
}
