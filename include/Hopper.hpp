#pragma once
#include <Enemigo.hpp>

class Hopper: public Enemigo
{
private:
    /* data */
public:
    Hopper(int x, int y) : Enemigo(x, y, "crawler", 9,3)
    {
        this->vida = 35;
    }
    ~Hopper() {}
};