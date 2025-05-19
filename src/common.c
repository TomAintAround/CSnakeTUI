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
