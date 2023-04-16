#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <memory>
#include <typeinfo>
#include "Exploration.h"

struct Point
{
    // in new co-ordinates
    int x;
    int y;
};

struct Obstacle
{
    Point center;
    double diameter;
};

class Workspace
{
public:
    Workspace();

    Point convertOldToNewPoint(Point old);

    double convertOldToNewDiameter(double old);

    std::vector<Point> getNeighbors(Point point);

    bool inObstacle(Point point, Obstacle obstacle);

    void printGrid();

    void printObstacles();

    void setAllToFreeSpace();

    int grid[ROW][COL] = {{0}};

    void A_star();

private:
    std::vector<Obstacle> obstacles;
};