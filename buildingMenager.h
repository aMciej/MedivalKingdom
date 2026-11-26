#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "buildings.h"
#include "resourceMenager.h"
#include "Kingdom.h"


class buildingMenager{
    std::vector<std::unique_ptr<Building>>buildings;
    resourceMenager& rM;
    buildingMenager(resourceMenager& rM);
    public:
    void createBuilding(BuildingType building);
    int numberOfBuildings(BuildingType building);
    void addResources();
};