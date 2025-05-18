#include <stdlib.h>
#include <stdio.h>
#include "common.h"

void error(const char* errorMessage) {
	perror(errorMessage);
	exit(1);
}
