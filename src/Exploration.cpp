#include "Exploration.h"

Point Exploration::convertnewToOldPoint(Point newPoint)
{
    struct Point old_coordinates;
    old_coordinates.x = (newPoint.y - 10) / 10;
    old_coordinates.y = (10 - newPoint.x) / 10;

    return old_coordinates;
}

bool Exploration::isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool Exploration::isUnBlocked(int grid[ROW][COL], int row, int col)
{

    if (grid[row][col] == 1)
        return (true);
    else
        return (false);
}

bool Exploration::isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}

double Exploration::calculateHValue(int row, int col, Pair dest)
{
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}

void Exploration::tracePath(cell cellDetails[][COL], Pair dest)
{
    int row = dest.first;
    int col = dest.second;

    std::stack<Pair> Path;

    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col))
    {

        Path.push(std::make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(std::make_pair(row, col));

    int size = Path.size();

    std::pair<int, int> p = Path.top();
    Point startPoint = {(double)p.first, (double)p.second};
    startPoint = convertnewToOldPoint(startPoint);
    wayPointList->insertWaypoint(startPoint, startPoint, startPoint);

    while (!Path.empty())
    {
        std::pair<int, int> p = Path.top();
        Point parent = {(double)p.first, (double)p.second};
        parent = convertnewToOldPoint(parent);

        Path.pop();

        if (!Path.empty())
        {
            std::pair<int, int> pp = Path.top();
            Point current = {(double)pp.first, (double)pp.second};
            current = convertnewToOldPoint(current);
            wayPointList->insertWaypoint(current, parent, startPoint);
        }
    }

    wayPointList->printList();
}

void Exploration::successor(int a, int b, Pair dest, int grid[ROW][COL], std::string direction)
{
    int number_a, number_b;

    for (int k = 0; k < 8; k++)
    {
        if (direction == directions[k])
        {
            number_a = a + (-1 * successors[k][0]);
            number_b = b + (-1 * successors[k][1]);
            break;
        }
    }

    // Only process this cell if this is a valid one
    if (this->isValid(a, b) == true)
    {
        if (this->isDestination(a, b, dest) == true)
        {
            cellDetails[a][b].parent_i = number_a;
            cellDetails[a][b].parent_j = number_b;

            tracePath(cellDetails, dest);
            foundDest = true;
            return;
        }

        else if (closedList[a][b] == false && this->isUnBlocked(grid, a, b) == true)
        {
            gNew = cellDetails[number_a][number_b].g + 1.0;
            hNew = calculateHValue(a, b, dest);
            fNew = gNew + hNew;

            if (cellDetails[a][b].f == FLT_MAX || cellDetails[a][b].f > fNew)
            {
                openList.insert(std::make_pair(
                    fNew, std::make_pair(a, b)));

                // Update the details of this cell
                cellDetails[a][b].f = fNew;
                cellDetails[a][b].g = gNew;
                cellDetails[a][b].h = hNew;
                cellDetails[a][b].parent_i = number_a;
                cellDetails[a][b].parent_j = number_b;
            }
        }
    }
}

void Exploration::aStarSearch(int grid[ROW][COL], Pair src, Pair dest)
{
    if (this->isValid(src.first, src.second) == false)
    {
        std::cout << "Source is invalid" << std::endl;
        return;
    }

    if (this->isValid(dest.first, dest.second) == false)
    {
        std::cout << "Destination is invalid" << std::endl;
        return;
    }

    if (this->isUnBlocked(grid, src.first, src.second) == false || this->isUnBlocked(grid, dest.first, dest.second) == false)
    {
        std::cout << "Source or the destination is blocked" << std::endl;
        return;
    }

    if (this->isDestination(src.first, src.second, dest) == true)
    {
        std::cout << "We are already at the destination" << std::endl;
        return;
    }

    memset(closedList, false, sizeof(closedList));

    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    // Initialising the parameters of the starting node
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    openList.insert(std::make_pair(0.0, std::make_pair(i, j)));

    while (!openList.empty())
    {
        pPair p = *openList.begin();

        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        // Loop through each successor and call the successor method
        for (int k = 0; k < 8 && !foundDest; k++)
        {
            int next_i = i + successors[k][0];
            int next_j = j + successors[k][1];

            this->successor(next_i, next_j, dest, grid, directions[k]);
        }
    }

    // When the destination cell is not found and the open list is empty, then we conclude that we failed to reach the destination cell.
    // This may happen when the there is no way to destination cell (due to blockages)
    if (foundDest == false)
        std::cout << "Failed to explore the workspace" << std::endl;

    return;
}
