#include "Workspace.h"


int main()
{

    std::shared_ptr<Workspace> obj = std::make_shared<Workspace>();
    obj->printGrid();
    obj->A_star();
}