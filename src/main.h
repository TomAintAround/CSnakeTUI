#ifndef MAIN_H
#define MAIN_H

#include "snake.h"

#define INIT_NUM 3
#define EASY_MODE 0.3
#define MEDIUM_MODE 0.2
#define HARD_MODE 0.1
#define PI 3.14159265358979323846

typedef struct {
	int x, y;
} apple_t;

/**
 * @brief Checks if 2 doubles are approximately the same value.
 * The order of the arguments are irrelevant.
 *
 * @param[in] number1 The first number.
 * @param[in] number1 The second number.
 * @return Whether the numbers are approximately the same or not.
 */
bool close(const double number1, const double number2);

/**
 * @brief Checks for user input and and change direction of the snake.
 *
 * @param[out] dx Pointer of the difference in the x axis.
 * @param[out] dy Pointer of the difference in the y axis.
 * @param[in] prevDX Previous difference of the x axis.
 * @param[in] prevDY Previous difference of the y axis.
 */
void translateInput(int* dx, int* dy, int prevDX, int prevDY);

/**
 * @brief Checks for user input and and change direction of the snake.
 *
 * @param[out] snake The pointer to the head of the snake (top of the stack).
 * @param[out] apple Pointer to the apple struct.
 * @param[in] rows The number of existing rows.
 * @param[in] cols The number of existing columns
 */
void placeApple(snakePart_t** snake, apple_t* apple, const int rows, const int cols);

#endif
