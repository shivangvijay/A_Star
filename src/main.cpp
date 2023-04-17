#include "Workspace.h"

int main()
{

    std::vector<Obstacle> Obstacles = {{{0, 0}, 1}, {{-1, 0}, 0.1}};
    Obstacles.push_back({{0, 1}, 1});      // obstacle-> ({center.x, center.y}, diameter)

    std::unique_ptr<Workspace> exploreWorkspace = std::make_unique<Workspace>(Obstacles);
    // exploreWorkspace->printGrid();
    exploreWorkspace->printObstacles();
    exploreWorkspace->explore();
}