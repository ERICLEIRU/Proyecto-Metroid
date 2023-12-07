#pragma once
#include <Enemigo.hpp>

class Crawler : public Enemigo
{
private:
    /* data */
public:
    Crawler(int posicionX, int posicionY) : Enemigo(posicionX, posicionY, 16, 15, 1, 22)
    {
        this->vida = 20;
        this->reductorVelocidad = 10;
    }
    void Actualizar()
    {
        if (this->cuentaRegresivaVelocidad < 0)
        {

            if (this->posicion.LeerX() > 790)
                this->posicion.AsignarX(0);
            this->posicion.DesplazarX(1);
            this->sprite.setPosition(this->posicion.LeerX(), this->posicion.LeerY());
            this->cuentaRegresivaVelocidad = this->reductorVelocidad;
        }
        else
            this->cuentaRegresivaVelocidad--;
    }
    ~Crawler() {}
};