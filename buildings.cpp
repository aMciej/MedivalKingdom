#include <iostream>

struct Building {
        virtual int costGold() const = 0;
        virtual int costWood() const = 0;
        virtual ~Building() {}
};

class Farm: public Building{
    int food = 30;
    public:
    int costGold() const override{
        return 50;
    }
    int costWood() const override{
        return 20;
    }
};

class LumberMill:public Building{
    int wood = 25;
    public:
    int costGold() const override{
        return 40;
    }
    int costWood() const override{
        return 0;
    }
};

class GoldMine:public Building{
    int gold = 40;
    public:
    int costGold() const override{
        return 100;
    }
    int costWood() const override{
        return 30;
    }
};

class House:public Building{
    int villagers = 2;
    public:
    int costGold() const override{
        return 30;
    }
    int costWood() const override{
        return 20;
    }
};