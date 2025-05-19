#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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
