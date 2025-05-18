#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "snake.h"
#include "common.h"

bool gameLost(snakePart_t** snake) {
	if ((*snake)->x < 0 || (*snake)->x > LIMIT_X) return true;
	if ((*snake)->y < 0 || (*snake)->y > LIMIT_Y) return true;
	return false;
}

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
		moveSnake(&snake, 0, 1);
		elapsedTime = clock();
	}
	printf("Game lost!\n");
	return 0;
}
