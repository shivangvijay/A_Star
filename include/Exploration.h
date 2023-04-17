#include "Waypoints.h"
class Exploration
{
public:

    bool isValid(int row, int col);

    // A structure to hold the necessary parameters
    struct cell
    {
        // Row and Column index of its parent
        // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
        int parent_i, parent_j;
        // f = g + h
        double f, g, h;

    };

    void Backtrace(cell cellDetails[][COL], Pair dest);

    bool isUnBlocked(int grid[ROW][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    void tracePath(cell cellDetails[][COL], Pair dest);
    void successor(int a, int b, Pair dest, int grid[ROW][COL], std::string direction);
    void aStarSearch(int grid[ROW][COL], Pair src, Pair dest);
    PointP convertnewToOldPoint(PointP old);

private:
    cell cellDetails[ROW][COL];
    bool foundDest = false;
    bool closedList[ROW][COL];
    double gNew, hNew, fNew;

    // Creating a shortcut for pair<int, pair<int, int>> type
    typedef std::pair<double, std::pair<int, int>> pPair;

    std::set<pPair> openList;
    bool flag = true;
};