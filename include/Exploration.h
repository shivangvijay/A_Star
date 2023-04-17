#include "Waypoints.h"
class Exploration
{
public:
    /**
     * @brief Structure to hold the necessary parameters
     *
     */
    struct cell
    {
        int parent_i, parent_j;

        double f, g, h; // f = g + h
    };

    /**
     * @brief Method to check whether grid is valid or not
     * Returns true if row number and column number is in range
     *
     * @param row
     * @param col
     * @return true
     * @return false
     */
    bool isValid(int row, int col);

    /**
     * @brief Method to check whether the given cell is blocked or not
     * Returns true if the cell is not blocked else false
     * @param grid
     * @param row
     * @param col
     * @return true
     * @return false
     */
    bool isUnBlocked(int grid[ROW][COL], int row, int col);

    /**
     * @brief Method to check whether destination grid has been reached or not
     *
     * @param row
     * @param col
     * @param dest
     * @return true
     * @return false
     */
    bool isDestination(int row, int col, Pair dest);

    /**
     * @brief Class method to calculate the 'h' heuristics.
     *
     * @param row
     * @param col
     * @param dest
     * @return double
     */
    double calculateHValue(int row, int col, Pair dest);

    /**
     * @brief Class method to trace the path from the source to destination
     *
     * @param cellDetails
     * @param dest
     */
    void tracePath(cell cellDetails[][COL], Pair dest);

    /**
     * @brief Generates the successors of a cell in the grid. (8 successor)
     *
     *       N.W    N   N.E
     *         \    |   /
     *          \   |  /
     *       W----current----E
     *           /  |  \
     *          /   |   \
     *       S.W    S   S.E
     *
     * @param a The row index of the current cell.
     * @param b The column index of the current cell.
     * @param dest The destination node.
     * @param grid The 2D array representing the grid.
     * @param direction The direction of movement from the parent node to the current node.
     *
     * @return void
     */
    void successor(int a, int b, Pair dest, int grid[ROW][COL], std::string direction);

    /**
     * @brief Class Method to find the shortest path between a given source cell to a destination cell according to A* Search Algorithm
     *
     * @param grid
     * @param src
     * @param dest
     */
    void aStarSearch(int grid[ROW][COL], Pair src, Pair dest);

    /**
     * @brief convert new co-ordinate point into old co-ordinate point
     *
     * @param newPoint
     * @return Point in old co-ordinate system
     */
    Point convertnewToOldPoint(Point newPoint);

private:
    cell cellDetails[ROW][COL];
    bool foundDest = false;
    bool closedList[ROW][COL];
    double gNew, hNew, fNew; // To store the 'g', 'h' and 'f' of the 8 successors

    std::set<pPair> openList;
    std::unique_ptr<WaypointHandler> wayPointList = std::make_unique<WaypointHandler>();
    const std::vector<std::string> directions = {"North", "South", "East", "West", "North-East", "North-West", "South-East", "South-West"};
    int successors[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
};