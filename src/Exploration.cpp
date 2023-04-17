#include "Waypoints.h"

Linkedlist finalList;

PointP Exploration::convertnewToOldPoint(PointP newPoint)
{
    struct PointP old_coordinates;
    old_coordinates.x = (newPoint.y - 10)/10;
    old_coordinates.y = (10 - newPoint.x)/10;

    return old_coordinates;
}


// A Utility Function to check whether given cell (row, col)
// is a valid cell or not.
bool Exploration::isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// A Utility Function to check whether the given cell is
// blocked or not

bool Exploration::isUnBlocked(int grid[ROW][COL], int row, int col)
{
    // Returns true if the cell is not blocked else false
    if (grid[row][col] == 1)
        return (true);
    else
        return (false);
}

// A Utility Function to check whether destination cell has
// been reached or not
bool Exploration::isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}

// A Utility Function to calculate the 'h' heuristics.
double Exploration::calculateHValue(int row, int col, Pair dest)
{
    // Return using the distance formula
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}

// A Utility Function to trace the path from the source
// to destination
void Exploration::tracePath(cell cellDetails[][COL], Pair dest)
{
    printf("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;

    std::stack<Pair> Path;
    // std::stack<PointP> oldPointPath;



    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) //while parameter become false when src destination comes
    {
        // std::cout << "I am here --> " << row << " " << col << std::endl;

        Path.push(std::make_pair(row, col));
        // PointP temp = convertnewToOldPoint({(double)row,(double)col});
        // oldPointPath.push(temp);
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;

    }

    // std::cout << "I am here --> " << row << " " << col << std::endl;


    Path.push(std::make_pair(row, col));
    // PointP temp = convertnewToOldPoint({(double)row,(double)col});
    // oldPointPath.push(temp);

    int size = Path.size();

    // while (!Path.empty())
    // {
    //     std::pair<int, int> p = Path.top();
    //     Path.pop();
    //     printf("-> (%d,%d) ", p.first, p.second);

    //     PointP tempPoint = {(double)p.first , (double)p.second}; 
        
    //     // finalList.insertNode(tempPoint, tempPoint);

    //     if(Path.size() == size-1)
    //     {
    //         finalList.insertNode(tempPoint, tempPoint);
    //     }
    //     else
    //     {
    //         if(!Path.empty())
    //         {
    //             std::pair<int, int> pp = Path.top();
    //             PointP tempPoint2 = {(double)pp.first , (double)pp.second};
    //             finalList.insertNode(tempPoint2, tempPoint);
    //         }
    //     }
        
    //     std::cout << std::endl;
    // }


    std::pair<int, int> p = Path.top();
    PointP startPoint = {(double)p.first , (double)p.second}; 
    startPoint = convertnewToOldPoint(startPoint);
    finalList.insertNode(startPoint, startPoint, startPoint);




    while (!Path.empty())
    {
        std::pair<int, int> p = Path.top();
        PointP tempPoint = {(double)p.first , (double)p.second}; 
        tempPoint = convertnewToOldPoint(tempPoint);


        Path.pop();

        if(!Path.empty())
        {
            std::pair<int, int> pp = Path.top();
            PointP tempPoint2 = {(double)pp.first , (double)pp.second};
            tempPoint2 = convertnewToOldPoint(tempPoint2);
            finalList.insertNode(tempPoint2, tempPoint, startPoint);

        }
        
    }



    finalList.printList();

    // std::cout << std::endl;
    printf("\nThe Path is real co-ordinates");

    // while (!oldPointPath.empty())
    // {
    //     PointP p = oldPointPath.top();
    //     oldPointPath.pop();
    //     printf("-> (%f,%f) ", p.x, p.y);
    // }

    return;
}

void Exploration::Backtrace(cell cellDetails[][COL], Pair dest)
{
    printf("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;

    std::stack<Pair> Path;
    // std::stack<PointP> oldPointPath;



    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) //while parameter become false when src destination comes
    {
        // std::cout << "I am here --> " << row << " " << col << std::endl;

        Path.push(std::make_pair(row, col));
        // PointP temp = convertnewToOldPoint({(double)row,(double)col});
        // oldPointPath.push(temp);
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;

    }

    // std::cout << "I am here --> " << row << " " << col << std::endl;


    Path.push(std::make_pair(row, col));
    // PointP temp = convertnewToOldPoint({(double)row,(double)col});
    // oldPointPath.push(temp);

    while (!Path.empty())
    {
        std::pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }

    // std::cout << std::endl;
    printf("\nThe Path is real co-ordinates");

    // while (!oldPointPath.empty())
    // {
    //     PointP p = oldPointPath.top();
    //     oldPointPath.pop();
    //     printf("-> (%f,%f) ", p.x, p.y);
    // }

    return;
}

// cell cellDetails[ROW][COL];
// bool foundDest = false;
// bool closedList[ROW][COL];
// double gNew, hNew, fNew;
// std::set<pPair> openList;
// bool flag = true;

void Exploration::successor(int a, int b, Pair dest, int grid[ROW][COL], std::string direction)
{

    int number_a;
    int number_b;
    if (direction == "North")
    {
        number_a = a + 1;
        number_b = b;
    }
    else if (direction == "South")
    {
        number_a = a - 1;
        number_b = b;
    }
    else if (direction == "East")
    {
        number_a = a;
        number_b = b - 1;
    }
    else if (direction == "West")
    {
        number_a = a;
        number_b = b + 1;
    }
    else if (direction == "North-East")
    {
        number_a = a + 1;
        number_b = b - 1;
    }
    else if (direction == "North-West")
    {
        number_a = a + 1;
        number_b = b + 1;
    }
    else if (direction == "South-East")
    {
        number_a = a - 1;
        number_b = b - 1;
    }
    else if (direction == "South-West")
    {
        number_a = a - 1;
        number_b = b + 1;
    }

    // Only process this cell if this is a valid one
    if (this->isValid(a, b) == true)
    {
        // If the destination cell is the same as the
        // current successor
        if (this->isDestination(a, b, dest) == true)
        {
            // Set the Parent of the destination cell
            // cellDetails[a][b].parent_i = i;
            cellDetails[a][b].parent_i = number_a;
            cellDetails[a][b].parent_j = number_b;


            // PointP Exploration::convertnewToOldPoint(PointP newPoint)
            // {
            //     struct PointP old_coordinates;
            //     old_coordinates.x = (newPoint.y - 10)/10;
            //     old_coordinates.y = (10 - newPoint.x)/10;

            //     return old_coordinates;
            // }

            PointP parent = convertnewToOldPoint({(double)number_a,(double)number_b});
            PointP current = convertnewToOldPoint({(double)a,(double)b});

            // std::cout << "Current->  [" << a << "," << b << "]  Parent->  [" << number_a << "," << number_b << "]" << std::endl;


            // waypoint.parent_i = parent.x;
            // waypoint.parent_j = parent.y;
            
            printf("The destination cell is found\n");
            flag = false;
            // list.printList();
            tracePath(cellDetails, dest);
            foundDest = true;
            return;
        }
        // If the successor is already on the closed
        // list or if it is blocked, then ignore it.
        // Else do the following
        else if (closedList[a][b] == false && this->isUnBlocked(grid, a, b) == true)
        {
            // gNew = cellDetails[i][b].g + 1.0;
            gNew = cellDetails[number_a][number_b].g + 1.0;

            hNew = calculateHValue(a, b, dest);
            fNew = gNew + hNew;

            // If it isn’t on the open list, add it to
            // the open list. Make the current square
            // the parent of this square. Record the
            // f, g, and h costs of the square cell
            //                OR
            // If it is on the open list already, check
            // to see if this path to that square is
            // better, using 'f' cost as the measure.
            if (cellDetails[a][b].f == FLT_MAX || cellDetails[a][b].f > fNew)
            {
                openList.insert(std::make_pair(
                    fNew, std::make_pair(a, b)));

                // Update the details of this cell
                cellDetails[a][b].f = fNew;
                cellDetails[a][b].g = gNew;
                cellDetails[a][b].h = hNew;
                // cellDetails[a][b].parent_i = i;
                cellDetails[a][b].parent_i = number_a;

                cellDetails[a][b].parent_j = number_b;

                PointP parent = convertnewToOldPoint({(double)number_a,(double)number_b});
                PointP current = convertnewToOldPoint({(double)a,(double)b});

                // std::cout << "Current->  [" << a << "," << b << "]  Parent->  [" << number_a << "," << number_b << "]" << std::endl;

            }
        }
    }
}

// A Function to find the shortest path between
// a given source cell to a destination cell according
// to A* Search Algorithm
void Exploration::aStarSearch(int grid[ROW][COL], Pair src, Pair dest)
{
    // If the source is out of range
    if (this->isValid(src.first, src.second) == false)
    {
        printf("Source is invalid\n");
        return;
    }

    // If the destination is out of range
    if (this->isValid(dest.first, dest.second) == false)
    {
        printf("Destination is invalid\n");
        return;
    }

    // Either the source or the destination is blocked
    if (this->isUnBlocked(grid, src.first, src.second) == false || this->isUnBlocked(grid, dest.first, dest.second) == false)
    {
        printf("Source or the destination is blocked\n");
        return;
    }

    // If the destination cell is the same as source cell
    if (this->isDestination(src.first, src.second, dest) == true)
    {
        printf("We are already at the destination\n");
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

    PointP parent = convertnewToOldPoint({(double)i,(double)j});
    PointP current = convertnewToOldPoint({(double)i,(double)j});

    // PointP temp = convertnewToOldPoint({20.0,0.0});

    // std::cout << i << " " <<  j << std::endl; 
    // std::cout << "Current->  [" << i << "," << j << "]  Parent->  [" << i << "," << j << "]" << std::endl;

    // std::cout << temp.x << " " << temp.y << std::endl;

    /*
     Create an open list having information as-
     <f, <i, j>>
     where f = g + h,
     and i, j are the row and column index of that cell
     Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
     This open list is implemented as a set of pair of
     pair.*/
    // set<pPair> openList;

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

        // To store the 'g', 'h' and 'f' of the 8 successors
        // double gNew, hNew, fNew;

        //----------- 1st Successor (North) ------------

        if (flag)
        {
            this->successor(i - 1, j, dest, grid, "North");
        }

        //----------- 2nd Successor (South) ------------
        if (flag)
        {
            this->successor(i + 1, j, dest, grid, "South");
        }

        //----------- 3rd Successor (East) ------------

        if (flag)
        {
            this->successor(i, j + 1, dest, grid, "East");
        }

        //----------- 4th Successor (West) ------------

        if (flag)
        {
            this->successor(i, j - 1, dest, grid, "West");
        }

        //----------- 5th Successor (North-East)
        if (flag)
        {
            this->successor(i - 1, j + 1, dest, grid, "North-East");
        }

        //----------- 6th Successor (North-West)
        //------------

        if (flag)
        {
            this->successor(i - 1, j - 1, dest, grid, "North-West");
        }

        //----------- 7th Successor (South-East)
        //------------

        if (flag)
        {
            this->successor(i + 1, j + 1, dest, grid, "South-East");
        }

        //----------- 8th Successor (South-West)

        if (flag)
        {
            this->successor(i + 1, j - 1, dest, grid, "South-West");
        }
    }

    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destination cell. This may happen when the
    // there is no way to destination cell (due to
    // blockages)
    if (foundDest == false)
        std::cout << "Failed to explore the workspace" << std::endl;

    return;
}
