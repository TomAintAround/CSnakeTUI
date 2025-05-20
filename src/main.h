#ifndef MAIN_H
#define MAIN_H

#define INIT_NUM 3
#define EASY_MODE 0.3
#define MEDIUM_MODE 0.2
#define HARD_MODE 0.1
#define PI 3.14159265358979323846

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
 * @param[inout] dx Pointer of the difference in the x axis.
 * @param[inout] dy Pointer of the difference in the y axis.
 */
void translateInput(int* dx, int* dy);

#endif
