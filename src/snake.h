#ifndef SNAKE_H
#define SNAKE_H

typedef struct SSnakePart {
	int x, y;
	struct SSnakePart* next;
} snakePart_t;

/**
 * @brief Initializes the snake.
 *
 * @param[out] snake The pointer to the head of the snake (top of the stack).
 */
void initSnake(snakePart_t** snake);

/**
 * @brief Inserts a new snake part in front of the head.
 *
 * @param[inout] snake The pointer to the head of the snake (top of the stack).
 * @param[in] x The abscissa of the new head.
 * @param[in] y The ordinate of the new head.
 */
void insertPart(snakePart_t** snake, int x, int y);

/**
 * @brief Moves the snake according to the input.
 *
 * @param[in] snake The pointer to the head of the snake (top of the stack).
 * @param[in] dx The moviment of the head in x the axis.
 * @param[in] dy The moviment of the head in y the axis.
 */
void moveSnake(snakePart_t** snake, int dx, int dy);

/**
 * @brief Removes all snake parts safely.
 *
 * @param[inout] snake The pointer to the head of the snake (top of the stack).
 */
void cleanSnake(snakePart_t** snake);

/**
 * @brief Checks if the game is lost (snake leaves the boundaries).
 *
 * @param[in] snake The pointer to the head of the snake (top of the stack).
 */
bool gameLost(snakePart_t** snake);

#endif
