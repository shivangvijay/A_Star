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

// Creating a shortcut for int, int pair type
typedef std::pair<int, int> Pair;

struct Point
{
    // in new co-ordinates
    int x;
    int y;
};

struct PointP
{
    // in new co-ordinates
    double x;
    double y;
};

struct Obstacle
{
    Point center;
    double diameter;
};

