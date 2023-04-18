#pragma once
#include "common.h"


/**
 * @brief Struct to store information about waypoints
 */
struct Waypoint {
public:
     Point parent; /**< The parent waypoint */
    Point current; /**< The current waypoint */
    Waypoint* next; /**< The next waypoint */
    double euclidean; /**< The Euclidean distance from the start point to the current waypoint */
    double manhathan; /**< The Manhattan distance from the start point to the current waypoint */
  
    /**
     * @brief Construct a new Waypoint object
     * 
     * @param current The current waypoint
     * @param parent The parent waypoint
     * @param startPoint The start point
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
     * @brief Calculates the Euclidean distance between the current waypoint and the start point
     * 
     * @param current The current waypoint
     * @param startPoint The start point
     * @return double The Euclidean distance
     */
    double calculateEuclidean(Point current, Point startPoint)
    {
        return sqrt(pow((current.x - startPoint.x),2) + pow((current.y - startPoint.y),2));
    }


    /**
     * @brief Calculates the Manhattan distance between the current waypoint and the start point
     * 
     * @param current The current waypoint
     * @param startPoint The start point
     * @return double The Manhattan distance
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