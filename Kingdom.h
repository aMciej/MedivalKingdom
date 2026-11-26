#include "resourceMenager.h"
#include "buildings.h"
#pragma once

enum class BuildingType {
    Farm,
    LumberMill,
    GoldMine,
    House
};

class Kingdom{
    private:
    int population = 10;
    int houseNumber = 10;
    int maxPopulation = houseNumber*2;
    int numberOfBuildings[4];
    resourceMenager rM;
    Farm farm;
    LumberMill lumberMill;
    GoldMine goldMine;
    House house;
    public:
    bool build(BuildingType building);
    int getGold();
    int getWood();
    int getPopulation();
    int getMaxPopulation();
    int increaseHouseNumber();
    int getHouseNumber();
    bool add();
    bool decrease();

};

