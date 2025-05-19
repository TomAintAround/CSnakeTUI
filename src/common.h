#ifndef COMMON_H
#define COMMON_H

#define LIMIT_X 100
#define LIMIT_Y 100
#define INIT_NUM 3
#define EASY_MODE 0.2
#define MEDIUM_MODE 0.05
#define HARD_MODE 0.02
#define PI 3.14159265358979323846

/**
 * @brief Exits the game with an error message and returns 1.
 *
 * @param[in] errorMessage The error message.
 */
void error(const char* errorMessage);

/**
 * @brief Checks if 2 doubles are approximately the same value.
 * The order of the arguments are irrelevant.
 *
 * @param[in] number1 The first number.
 * @param[in] number1 The second number.
 */
bool close(const double number1, const double number2);

#endif
