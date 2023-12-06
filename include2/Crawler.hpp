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
        // this->posicion.AsignarY(y);
    }
    void Actualizar()
    {
        if (this->posicion.LeerX() > 790)
            this->posicion.AsignarX(0);
        this->posicion.DesplazarX(1);
        this->sprite.setPosition(this->posicion.LeerX(), this->posicion.LeerY());
    }
    ~Crawler() {}
};