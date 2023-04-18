#pragma once
#include "Exploration.h"

/**
 * @brief class workspace is contain methods to maintain the workspace  
 * 
 */
class Workspace
{
public:
    /**
     * @brief Construct a new Workspace object
     * 
     * @param obstacleInOld 
     * It take param list of obstacles in old-coordinate system
     */
    Workspace(std::vector<Obstacle> obstacleInOld);

    /**
     * @brief Method do necessary steps for Workspace setup 
     * 
     */
    void initialize();

    /**
     * @brief convert old co-ordinate point into new co-ordinate point
     * 
     * @param old
     * @return Point in new co-ordinate system
     */
    Point convertOldToNewPoint(Point old);

    /**
     * @brief convert old co-ordinate diameter into new co-ordinate diameter
     * 
     * @param old 
     * @return double in new co-ordinate system
     */
    double convertOldToNewDiameter(double old);

    /**
     * @brief check point is in obstacle or not
     * 
     * @param point 
     * @param obstacle 
     * @return true 
     * @return false 
     */
    bool inObstacle(Point point, Obstacle obstacle);

    /**
     * @brief console prints of grids of new co-ordinates
     * 
     */
    void printGrid();

    /**
     * @brief console prints of obstacle in old co-ordinates
     * 
     */
    void printObstacles();

    /**
     * @brief Set the All To Free Space object
     * Initalize workspace with all grids in obstacle(0), this method convert all grids to free space(1)
     */
    void setAllToFreeSpace();

    /**
     * @brief give start, end co-ordintes and explore the workspace.
     * 
     */
    void explore();

private:
    std::vector<Obstacle> obstacles;
    std::vector<Obstacle> obstacleInOld;
    int grid[ROW][COL] = {{0}};
    std::unique_ptr<Exploration> exploration = std::make_unique<Exploration>();
};