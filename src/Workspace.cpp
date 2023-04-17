#include "Workspace.h"

// const double RESOLUTION = 0.1;

Workspace::Workspace(std::vector<Obstacle> obstacleInOld)
{
    this->obstacleInOld = obstacleInOld;
    this->initialize();
}

void Workspace::initialize()
{
    for (int i = 0; i < this->obstacleInOld.size(); i++)
    {
        obstacles.push_back({convertOldToNewPoint(this->obstacleInOld[i].center), convertOldToNewDiameter(this->obstacleInOld[i].diameter)});
    }

    this->setAllToFreeSpace();

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            for (Obstacle obstacle : obstacles)
            {
                if (inObstacle({(double)i, (double)j}, obstacle))
                {
                    grid[i][j] = 0;
                    break;
                }
            }
        }
    }
}

Point Workspace::convertOldToNewPoint(Point old)
{
    struct Point new_coordinates;
    new_coordinates.x = 10 - (10 * old.y);
    new_coordinates.y = 10 + (10 * old.x);
    return new_coordinates;
}

double Workspace::convertOldToNewDiameter(double old)
{
    return old * 10;
}

bool Workspace::inObstacle(Point point, Obstacle obstacle)
{
    double number = obstacle.diameter / 2.0;
    double distance = sqrt(pow((point.x + 1) - (obstacle.center.x + 1), 2) + pow((point.y + 1) - (obstacle.center.y + 1), 2));
    return distance <= (number);
}

void Workspace::printGrid()
{
    int n = ROW;
    int m = COL;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Workspace::printObstacles()
{
    for (Obstacle obstacle : this->obstacleInOld)
    {
        std::cout << "Obstacle at (" << obstacle.center.x << ", " << obstacle.center.y << ") with diameter " << obstacle.diameter << std::endl;
    }

    std::cout << std::endl;
}

void Workspace::setAllToFreeSpace()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            grid[i][j] = 1;
        }
    }
}

void Workspace::explore()
{
    Pair src = std::make_pair(20, 0);
    Pair dest = std::make_pair(0, 20);
    exploration->aStarSearch(grid, src, dest);
}