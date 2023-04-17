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
