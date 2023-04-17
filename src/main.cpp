#include "Workspace.h"

int main()
{

    std::vector<Obstacle> Obstacles = {{{0, 0}, 1}, {{-1, 0}, 0.1}};
    Obstacles.push_back({{0, 1}, 1});      // ({center.x, center.y}, diameter)

    std::shared_ptr<Workspace> exploreWorkspace = std::make_shared<Workspace>(Obstacles);
    exploreWorkspace->printGrid();
    exploreWorkspace->printObstacles();
    exploreWorkspace->explore();
}