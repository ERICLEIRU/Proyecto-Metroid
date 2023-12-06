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
    void Actualizar()
    {
        if (this->posicion.LeerY() > 790 && this->posicion.LeerDireccionY() == 1 || this->posicion.LeerY() < 0 && this->posicion.LeerDireccionY() == -1)
            this->posicion.CambiarDireccionY();

        this->posicion.DesplazarY(1);
        this->sprite.setPosition(this->posicion.LeerX(), this->posicion.LeerY());
    }
    ~Mellow() {}
};