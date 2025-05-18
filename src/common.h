#ifndef COMMON_H
#define COMMON_H

#define LIMIT_X 100
#define LIMIT_Y 100
#define INIT_NUM 3
#define EASY_MODE 0.2
#define MEDIUM_MODE 0.05
#define HARD_MODE 0.02

/**
 * @brief Exits the game with an error message and returns 1.
 *
 * @param[in] errorMessage The error message.
 */
void error(const char* errorMessage);

#endif
