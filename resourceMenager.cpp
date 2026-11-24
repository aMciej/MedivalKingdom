#include <iostream>
#include "resourceMenager.h"

int resourceMenager::get(resource resourcetype){
    switch(resourcetype){
        case gold:
            return goldAmount;
        case food:
            return foodAmount;
        case wood:
            return woodAmount;
        default: return -1;
    }
};

void resourceMenager::add(resource resourcetype, int value){
    switch(resourcetype){
        case gold:
            goldAmount = goldAmount + value;
            break;
        case food:
            foodAmount = foodAmount + value;
            break;
        case wood:
            woodAmount = woodAmount + value;
            break;
        default: return;
    }
};

bool resourceMenager::remove(resource resourcetype, int value){
    switch(resourcetype){
        case gold:
            if (goldAmount < value){
                return false;
            }
            goldAmount = goldAmount - value;
            return true;
        case food:
            if (foodAmount < value){
                return false;
            }
            foodAmount = foodAmount - value;
            return true;
        case wood:
            if (woodAmount < value){
                return false;
            }
            woodAmount = woodAmount - value;
            return true;
        default: return false;
    }
};
