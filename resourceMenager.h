#include <iostream>
#pragma once

class resourceMenager{
    int goldAmount = 100;
    int foodAmount = 100;
    int woodAmount = 100;
    public:
    enum resource{gold, food, wood};
    int get(resource resourcetype);
    void add(resource resourcetype, int value);
    bool remove(resource resourcetype, int value);
};