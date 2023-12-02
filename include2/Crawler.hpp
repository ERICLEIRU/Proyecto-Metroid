#pragma once
#include <Enemigo.hpp>

class Crawler : public Enemigo
{
private:
    /* data */
public:
    Crawler(int x, int y) : Enemigo(x, y, "Enemies", 9, 3)
    {
        this->vida = 20;
    }
    ~Crawler() {}
};