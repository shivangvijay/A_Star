#include "Waypoints.h"



  
// Function to insert a new node.
void Linkedlist::insertNode(PointP current, PointP parent, PointP startPoint)
{
    // Create the new Waypoint.
    Waypoint* newNode = new Waypoint(current, parent, startPoint);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Waypoint* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}
  
// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Waypoint* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        std::cout << "List empty" << std::endl;
        return;
    }
  
    int count = 1;
    // Traverse the list.
    while (temp != NULL) {
        std::cout << "Path co-ordinate " << count  << " -->  [" << temp->current.x << "," << temp->current.y 
                << "],  Parent->  [" << temp->parent.x << "," << temp->parent.y << "], Manhathan-> " << temp->mahathan 
                << ", Euclian-> " << temp->euclidian  << std::endl;
        temp = temp->next;
        count = count + 1;
    }
}