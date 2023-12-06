#pragma once
#include <Enemigo.hpp>

class Crawler : public Enemigo
{
private:
    /* data */
public:
    Crawler(int x, int y) : Enemigo(x, y, 16, 15, 1, 22)
    {
        this->vida = 20;
    }
    ~Crawler() {}
};