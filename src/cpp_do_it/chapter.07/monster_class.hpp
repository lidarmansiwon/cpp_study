#pragma once
#include <iostream>

class character {
public:
    character();
protected:
    int hp;
    int power;
};

class player : public character {
public:
    player();
};

class monster {
public:
    monster();
    virtual void attack_special(player target_player);
    void get_damage(int _damage);
    void attack(player target_player);
};
