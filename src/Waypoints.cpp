#include "Waypoints.h"

WaypointHandler::WaypointHandler()
{
    head = NULL;
}

void WaypointHandler::insertWaypoint(PointP current, PointP parent, PointP startPoint)
{
    Waypoint *newNode = new Waypoint(current, parent, startPoint);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Waypoint *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void WaypointHandler::printList()
{
    Waypoint *temp = head;

    if (head == NULL)
    {
        std::cout << "List empty" << std::endl;
        return;
    }

    int count = 1;

    while (temp != NULL)
    {
        std::cout << "Path co-ordinate " << count << " -->  [" << temp->current.x << "," << temp->current.y
                  << "],  Parent->  [" << temp->parent.x << "," << temp->parent.y << "], Manhathan-> " << temp->manhathan
                  << ", Euclian-> " << temp->euclidean << std::endl;
        temp = temp->next;
        count = count + 1;
    }
}