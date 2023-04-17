#include <iostream>
#include "Exploration.h"
#include "math.h"
#include <cstdlib>

struct Waypoint {
public:
    PointP parent;
    PointP current;
    Waypoint* next;
    double euclidian;
    double mahathan;
  
  
    // Parameterised Constructor
    Waypoint(PointP current, PointP parent, PointP startPoint)
    {
        this->parent = parent;
        this->current = current;
        this->euclidian = euclidianM(this->current, startPoint);
        this->mahathan = manhathanM(this->current, startPoint);
        this->next = NULL;
    }

    double euclidianM(PointP current, PointP startPoint)
    {
        return sqrt(pow((current.x - startPoint.x),2) + pow((current.y - startPoint.y),2));
    }

    double manhathanM(PointP current, PointP startPoint)
    {
        return (abs(current.x - startPoint.x) + abs(current.y - startPoint.y));
    }
};


  
// Linked list class to
// implement a linked list.
class Linkedlist {
    Waypoint* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(PointP current, PointP parent,PointP startPoint);
  
    // Function to print the
    // linked list.
    void printList();

};