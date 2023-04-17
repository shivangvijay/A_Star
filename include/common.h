#pragma once
#include <iostream>
#include <utility>
#include <math.h>
#include <stack>
#include <set>
#include <cfloat>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
#include <memory>
#include <typeinfo>

#define ROW 21
#define COL 21

#define RESET    "\033[0m"
#define BLUE     "\033[34m"
#define MAGENTA  "\033[35m"
#define RED      "\033[31m"
#define YELLOW   "\033[33m"
#define CYAN     "\033[36m"
#define BOLDRED  "\033[1m\033[31m"

/**
 * @brief Creating a shortcut for int, int pair type
 *
 */
typedef std::pair<int, int> Pair;

/**
 * @brief Creating a shortcut for pair<int, pair<int, int>> type
 *
 */
typedef std::pair<double, std::pair<int, int>> pPair;

/**
 * @brief A struct representing a point in 2D space
 *
 */
struct Point
{
    /**
     * @brief The x-coordinate of the point.
     *
     */
    double x;

    /**
     * @brief The y-coordinate of the point.
     *
     */
    double y;
};

/**
 * @brief A struct representing a circular obstacle in 2D space.
 *
 */
struct Obstacle
{
    /**
     * @brief The center point of the obstacle.
     *
     */
    Point center;

    /**
     * @brief The diameter of the obstacle.
     *
     */
    double diameter;
};
