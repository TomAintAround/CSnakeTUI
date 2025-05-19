#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "snake.h"
#include "common.h"

bool gameLost(snakePart_t** snake) {
	if ((*snake)->x < 0 || (*snake)->x > LIMIT_X) return true;
	if ((*snake)->y < 0 || (*snake)->y > LIMIT_Y) return true;
	return false;
}

void translateInput(int* dx, int* dy) {
	double angles[4] = { -PI / 2, -PI, PI / 2, 0 };
	double angle = angles[0];
	char key = getchar();
	if (key == '\033') {
		key = getchar();
		key = getchar();
		if (key == 'A') {
			angle = angles[0];
		} else if (key == 'B') {
			angle = angles[2];
		} else if (key == 'C') {
			angle = angles[3];
		} else if (key == 'D') {
			angle = angles[1];
		}
	} else {
		if (key == 'w' || key == 'W') {
			angle = angles[0];
		} else if (key == 'a' || key == 'A') {
			angle = angles[1];
		} else if (key == 's' || key == 'S') {
			angle = angles[2];
		} else if (key == 'd' || key == 'D') {
			angle = angles[3];
		}
	}
	while (getchar() != '\n');

	// To avoid 180º turns
	if (!close(*dx, -cos(angle)) || !close(*dy, -sin(angle))) {
		*dx = cos(angle);
		*dy = sin(angle);
	}
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
