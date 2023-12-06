#pragma once
#include <Enemigo.hpp>

class Mellow : public Enemigo
{
private:
    /* data */
public:
    Mellow(int x, int y) : Enemigo(x, y, 16, 8, 311, 21)
    {
        this->vida = 5;
    }
    ~Mellow() {}
};