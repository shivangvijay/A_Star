#include "Waypoints.h"

WaypointHandler::WaypointHandler()
{
    head = NULL;
}

void WaypointHandler::insertWaypoint(Point current, Point parent, Point startPoint)
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
        std::cout << BOLDRED << "List empty" << RESET << std::endl;
        return;
    }

    int count = 1;

    while (temp != NULL)
    {
        std::cout << YELLOW << "Path co-ordinate " << count << " -->  [" << temp->current.x << "," << temp->current.y
                  << "]," << BLUE  << "   Parent->  [" << temp->parent.x << "," << temp->parent.y << "],"<< CYAN << "  Manhathan-> " << temp->manhathan
                  << "," << RED << "  Euclian-> " << temp->euclidean << RESET << std::endl;
        temp = temp->next;
        count = count + 1;
    }
}