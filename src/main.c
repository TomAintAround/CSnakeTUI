#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "snake.h"
#include "common.h"

int main() {
	snakePart_t* snake;
	initSnake(&snake);
	int initX = LIMIT_X / 2;
	int initY = LIMIT_Y / 2;
	for (int i = INIT_NUM - 1; i >= 0; i--) {
		insertPart(&snake, initX - i, initY);
	}

	double frameDuration = MEDIUM_MODE;
	clock_t elapsedTime = clock();
	int dx = 0, dy = 0;
	while (!gameLost(&snake)) {
		if ((double)(clock() - elapsedTime) / CLOCKS_PER_SEC < frameDuration) {
			continue;
		}

		snakePart_t* part = snake;
		while (part != NULL) {
			printf("%d,%d ", part->x, part->y);
			part = part->next;
		}
		part = snake;
		printf("\n-=-=-=-\n");

		translateInput(&dx, &dy);
		moveSnake(&snake, dx, dy);
		elapsedTime = clock();
	}
	printf("Game lost!\n");

	return 0;
}
