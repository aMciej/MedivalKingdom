#include <iostream>
#include "Kingdom.h"
#include "resourceMenager.h"

int Kingdom::getGold(){
    return rM.get(resourceMenager::gold);
}

int Kingdom::getWood(){
    return rM.get(resourceMenager::wood);
}

int Kingdom::getPopulation(){
    return population;
}

int Kingdom::getMaxPopulation(){
    return maxPopulation;
}

int Kingdom::getHouseNumber(){
    return houseNumber;
}

int Kingdom::increaseHouseNumber(){
    houseNumber+=1;
    maxPopulation+=2;
    return houseNumber;
}

bool Kingdom::add(){
    if(population < maxPopulation){
        population+=1;
        return true;
    }else{
        return false;
    }
};

bool Kingdom::decrease(){
    if(population >0){
        population-=1;
        return true;
    }else{
        return false;    
    }
}

bool Kingdom::build(BuildingType building){
    int buildingCostGold = 0;
    int buildingCostWood = 0;
    switch(building){
    case BuildingType::Farm:
        buildingCostGold = farm.costGold();
        buildingCostWood = farm.costWood();
    break;
    case BuildingType::LumberMill:
        buildingCostGold = lumberMill.costGold();
        buildingCostWood = lumberMill.costWood();
    break;
    case BuildingType::GoldMine:
        buildingCostGold = goldMine.costGold();
        buildingCostWood = goldMine.costWood();
    break;
    case BuildingType::House:
        buildingCostGold = house.costGold();
        buildingCostWood = house.costWood();     
    break;
    }
    if(rM.get(resourceMenager::gold) >= buildingCostGold and 
        rM.get(resourceMenager::wood) >= buildingCostWood){
        rM.remove(resourceMenager::gold, buildingCostGold);
        rM.remove(resourceMenager::wood, buildingCostWood);
        numberOfBuildings[static_cast<int>(building)]++;
        return true;
    }else{
        return false;
    }
};

