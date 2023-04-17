#include "common.h"


/**
 * @brief To store all the information regarding waypoints. 
 * Parent waypoint, Euclidean cumulative distance and Manhathan cumulative distance 
 * 
 */
struct Waypoint {
public:
    Point parent;
    Point current;
    Waypoint* next;
    double euclidean;
    double manhathan;
  
    /**
     * @brief Construct a new Waypoint object
     * 
     * @param currentWaypoint
     * @param parentWaypoint
     * @param startPoint 
     */
    Waypoint(Point current, Point parent, Point startPoint)
    {
        this->parent = parent;
        this->current = current;
        this->euclidean = calculateEuclidean(this->current, startPoint);
        this->manhathan = calculateManhathan(this->current, startPoint);
        this->next = NULL;
    }


    /**
     * @brief used to calculate Euclidean distance between start point and current waypoint
     * 
     * @param current 
     * @param startPoint 
     * @return double 
     */
    double calculateEuclidean(Point current, Point startPoint)
    {
        return sqrt(pow((current.x - startPoint.x),2) + pow((current.y - startPoint.y),2));
    }


    /**
     * @brief used to calculate Manhathan distance between start point and current waypoint
     * 
     * @param current 
     * @param startPoint 
     * @return double 
     */
    double calculateManhathan(Point current, Point startPoint)
    {
        return (abs(current.x - startPoint.x) + abs(current.y - startPoint.y));
    }
};



/**
 * @brief Class to handle the waypoints.
 * 
 */
class WaypointHandler {  
public:
    /**
     * @brief Construct a new Waypoint Handler object
     * 
     */
    WaypointHandler();
  
    /**
     * @brief Method to insert a waypoint at the end of the list.
     * 
     * @param current 
     * @param parent 
     * @param startPoint 
     */
    void insertWaypoint(Point current, Point parent,Point startPoint);

    /**
     * @brief Method to print the complete list of waypoints
     * 
     */
    void printList();

private:
    Waypoint* head;

};