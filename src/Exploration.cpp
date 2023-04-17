#include "Exploration.h"
#include <algorithm>

PointP Exploration::convertnewToOldPoint(PointP newPoint)
{
    struct PointP old_coordinates;
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
    PointP startPoint = {(double)p.first, (double)p.second};
    startPoint = convertnewToOldPoint(startPoint);
    wayPointList->insertWaypoint(startPoint, startPoint, startPoint);

    while (!Path.empty())
    {
        std::pair<int, int> p = Path.top();
        PointP parent = {(double)p.first, (double)p.second};
        parent = convertnewToOldPoint(parent);

        Path.pop();

        if (!Path.empty())
        {
            std::pair<int, int> pp = Path.top();
            PointP current = {(double)pp.first, (double)pp.second};
            current = convertnewToOldPoint(current);
            wayPointList->insertWaypoint(current, parent, startPoint);
        }
    }

    wayPointList->printList();
}

void Exploration::successor(int a, int b, Pair dest, int grid[ROW][COL], std::string direction)
{
    static const std::vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
    static const std::vector<int> dy = {0, 1, 0, -1, -1, 1, -1, 1};
    static const std::vector<std::string> dir = {"North", "East", "South", "West", "North-East", "North-West", "South-East", "South-West"};
    auto it = std::find(dir.begin(), dir.end(), direction);
    int k = it - dir.begin();
    int x = a + dx[k];
    int y = b + dy[k];

    if (!isValid(a, b) || closedList[a][b] || !isUnBlocked(grid, a, b))
        return;

    if (isDestination(a, b, dest))
    {
        cellDetails[a][b].parent_i = x;
        cellDetails[a][b].parent_j = y;
        reachedFlag = false;
        tracePath(cellDetails, dest);
        foundDest = true;
        return;
    }

    float gNew = cellDetails[x][y].g + 1.0;
    float hNew = calculateHValue(a, b, dest);
    float fNew = gNew + hNew;

    if (cellDetails[a][b].f == FLT_MAX || cellDetails[a][b].f > fNew)
    {
        openList.insert({fNew, {a, b}});
        cellDetails[a][b].f = fNew;
        cellDetails[a][b].g = gNew;
        cellDetails[a][b].h = hNew;
        cellDetails[a][b].parent_i = x;
        cellDetails[a][b].parent_j = y;
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

    // Create a closed list and initialise it to false which
    // means that no cell has been included yet This closed
    // list is implemented as a boolean 2D array
    // bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    // Declare a 2D array of structure to hold the details
    // of that cell
    // cell cellDetails[ROW][COL];

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


    // Put the starting cell on the open list and set its
    // 'f' as 0
    openList.insert(std::make_pair(0.0, std::make_pair(i, j)));

    // We set this boolean value as false as initially
    // the destination is not reached.
    // bool foundDest = false;

    while (!openList.empty())
    {
        pPair p = *openList.begin();

        // Remove this vertex from the open list
        openList.erase(openList.begin());

        // Add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        /*
         Generating all the 8 successor of this cell

             N.W   N   N.E
               \   |   /
                \  |  /
             W----Cell----E
                  / | \
                /   |  \
             S.W    S   S.E

         Cell-->Popped Cell (i, j)
         N -->  North       (i-1, j)
         S -->  South       (i+1, j)
         E -->  East        (i, j+1)
         W -->  West           (i, j-1)
         N.E--> North-East  (i-1, j+1)
         N.W--> North-West  (i-1, j-1)
         S.E--> South-East  (i+1, j+1)
         S.W--> South-West  (i+1, j-1)*/

        //----------- 1st Successor (North) ------------

        if (reachedFlag)
        {
            this->successor(i - 1, j, dest, grid, "North");
        }

        //----------- 2nd Successor (South) ------------
        if (reachedFlag)
        {
            this->successor(i + 1, j, dest, grid, "South");
        }

        //----------- 3rd Successor (East) ------------

        if (reachedFlag)
        {
            this->successor(i, j + 1, dest, grid, "East");
        }

        //----------- 4th Successor (West) ------------

        if (reachedFlag)
        {
            this->successor(i, j - 1, dest, grid, "West");
        }

        //----------- 5th Successor (North-East)
        if (reachedFlag)
        {
            this->successor(i - 1, j + 1, dest, grid, "North-East");
        }

        //----------- 6th Successor (North-West)
        //------------

        if (reachedFlag)
        {
            this->successor(i - 1, j - 1, dest, grid, "North-West");
        }

        //----------- 7th Successor (South-East)
        //------------

        if (reachedFlag)
        {
            this->successor(i + 1, j + 1, dest, grid, "South-East");
        }

        //----------- 8th Successor (South-West)

        if (reachedFlag)
        {
            this->successor(i + 1, j - 1, dest, grid, "South-West");
        }
    }

    // When the destination cell is not found and the open list is empty, then we conclude that we failed to reach the destination cell.
    // This may happen when the there is no way to destination cell (due to blockages)
    if (foundDest == false)
        std::cout << "Failed to explore the workspace" << std::endl;

    return;
}
