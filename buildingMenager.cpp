#include "buildingMenager.h"

buildingMenager::buildingMenager(resourceMenager& rM)
: rM(rM){

};

void buildingMenager::createBuilding(BuildingType building){
    switch(building){
    case BuildingType::Farm:
    buildings.push_back(std::make_unique<Farm>());
    break;
    case BuildingType::LumberMill:
    buildings.push_back(std::make_unique<LumberMill>());
    break;
    case BuildingType::GoldMine:
    buildings.push_back(std::make_unique<GoldMine>());
    break;
    case BuildingType::House:   
    buildings.push_back(std::make_unique<House>());
    break;
    }
};

int buildingMenager::numberOfBuildings(BuildingType building) {
    int counter = 0;
    for (const auto& currentBuilding : buildings) {
        switch (building) {
        case BuildingType::Farm:
            if (dynamic_cast<Farm*>(currentBuilding.get()))
                counter+=1;
            break;

        case BuildingType::LumberMill:
            if (dynamic_cast<LumberMill*>(currentBuilding.get()))
                counter+=1;
            break;

        case BuildingType::GoldMine:
            if (dynamic_cast<GoldMine*>(currentBuilding.get()))
                counter+=1;
            break;

        case BuildingType::House:
            if (dynamic_cast<House*>(currentBuilding.get()))
                counter+=1;
            break;
        }
    }
    return counter;
}

void buildingMenager::addResources() {
    for (const auto& currentBuilding : buildings) {
        if (auto farm = dynamic_cast<Farm*>(currentBuilding.get())) {
            rM.add(resourceMenager::food, farm->getFood());
        }
        else if (auto lumberMill = dynamic_cast<LumberMill*>(currentBuilding.get())) {
            rM.add(resourceMenager::wood, lumberMill->getWood());
        }
        else if (auto goldMine = dynamic_cast<GoldMine*>(currentBuilding.get())) {
            rM.add(resourceMenager::gold, goldMine->getGold());
        }
    }
}