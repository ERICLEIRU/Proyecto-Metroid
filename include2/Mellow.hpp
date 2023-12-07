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
        this->reductorVelocidad = 2;
    }
    void Actualizar()
    {
        if (this->cuentaRegresivaVelocidad < 0)
        {
            if (this->posicion.LeerY() > 270 && this->posicion.LeerDireccionY() == 1 || this->posicion.LeerY() < 0 && this->posicion.LeerDireccionY() == -1)
                this->posicion.CambiarDireccionY();

            this->posicion.DesplazarY(1);
            this->sprite.setPosition(this->posicion.LeerX(), this->posicion.LeerY());

            this->cuentaRegresivaVelocidad = this->reductorVelocidad;
        }
        else
            this->cuentaRegresivaVelocidad--;
    }
    ~Mellow() {}
};