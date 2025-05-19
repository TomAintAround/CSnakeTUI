#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ncurses.h>
#include "common.h"

void error(const char* errorMessage) {
	perror(errorMessage);
	exit(1);
}

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
