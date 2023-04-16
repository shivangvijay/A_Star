#include "Workspace.h"

using namespace std;

const double RESOLUTION = 0.1;

Workspace::Workspace()
{
    // Initialize the workspace with obstacles
    vector<Obstacle> obs = {{{0, 0}, 1}};
    // std::cout << obs[0] << std::endl;

    for (int i = 0; i < obs.size(); i++)
    {
        // std::cout << convertOldToNewDiameter(obs[i].diameter) << std::endl;
        // std::cout << convertOldToNewPoint(obs[i].center) << std::endl;
        obstacles.push_back({convertOldToNewPoint(obs[i].center), convertOldToNewDiameter(obs[i].diameter)});
    }

    // obstacles.push_back({{10, 10}, 20});

    // obstacles.push_back({{10, 10}, 3});
    // obstacles.push_back({{15, 5}, 1.5});

    this->setAllToFreeSpace();

    // Initialize the grid with obstacle values
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            for (Obstacle obstacle : obstacles)
            {
                if (inObstacle({i, j}, obstacle))
                {
                    grid[ROW - 1 - i][j] = 0;
                    break;
                }
            }
        }
    }
}

Point Workspace::convertOldToNewPoint(Point old)
{
    struct Point new_coordinates;
    new_coordinates.x = 10 * old.x + 10;
    new_coordinates.y = 10 * old.y + 10;
    return new_coordinates;
}

double Workspace::convertOldToNewDiameter(double old)
{
    return old * 10;
}

vector<Point> Workspace::getNeighbors(Point point)
{
    vector<Point> neighbors;

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0)
            {
                continue;
            }

            int x = point.x + dx;
            int y = point.y + dy;

            if (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0)
            {
                neighbors.push_back({x, y});
            }
        }
    }

    return neighbors;
}

bool Workspace::inObstacle(Point point, Obstacle obstacle)
{
    double number = obstacle.diameter / 2.0;
    // std::cout << point.x+1 << "  " << point.y+1 << "   " << obstacle.center.x+1 << "    " << number << std::endl;
    double distance = sqrt(pow((point.x + 1) - (obstacle.center.x + 1), 2) + pow((point.y + 1) - (obstacle.center.y + 1), 2));
    // std::cout << "Distance  :----> " << distance << std::endl;
    // if()
    return distance <= (number);
}

void Workspace::printGrid()
{
    int n = ROW;
    int m = COL;

    // Iterating over all 1-D arrays in 2-D array
    for (int i = 0; i < n; i++)
    {

        // Printing all elements in ith 1-D array
        for (int j = 0; j < m; j++)
        {

            // Printing jth element of ith row
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Workspace::printObstacles()
{
    for (Obstacle obstacle : obstacles)
    {
        cout << "Obstacle at (" << obstacle.center.x << ", " << obstacle.center.y << ") with diameter " << obstacle.diameter << endl;
    }
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

int grid[ROW][COL] = {{0}};

void Workspace::A_star()
{
    Exploration obj;
    Pair src = make_pair(20, 0);

    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 20);

    obj.aStarSearch(grid, src, dest);
}