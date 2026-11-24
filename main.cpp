#include <iostream>
// #include "buildings.h"
#include "resourceMenager.h"

int main(){
    // Farm f;
    // Building* b = &f;
    // std::cout << b -> costGold() << std::endl;
    resourceMenager r;
    r.add(resourceMenager::gold, 50);
    r.remove(resourceMenager::gold,30);
    std::cout << r.get(resourceMenager::gold) << std::endl;
}