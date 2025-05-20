#ifndef UI_H
#define UI_H

#include "main.h"
#include "snake.h"

/**
 * @brief Draws the borders.
 *
 * @param[in] rows The number of existing rows.
 * @param[in] cols The number of existing columns.
 */
void drawBorders(const int rows, const int cols);

/**
 * @brief Checks if there's a snake part in a coordinate.
 *
 * @param[in] snake Pointer to the head of the snake (top of the stack).
 * @param[in] rows The number of existing rows.
 * @param[in] cols The number of existing columns.
 * @return Whether this coordinate has a snake part or not.
 */
bool isSnake(snakePart_t** snake, int row, int col);

/**
 * @brief Draws the snake.
 *
 * @param[in] snake Pointer to the head of the snake (top of the stack).
 * @param[in] rows The number of existing rows.
 * @param[in] cols The number of existing columns.
 */
void drawElements(snakePart_t** snake, apple_t* apple, const int rows, const int cols);

/**
 * @brief Draws the snake and the borders.
 *
 * @param[in] snake Pointer to the head of the snake (top of the stack).
 * @param[in] rows The number of existing rows.
 * @param[in] cols The number of existing columns.
 */
void drawMap(snakePart_t** snake, apple_t* apple, const int rows, const int cols);

#endif
