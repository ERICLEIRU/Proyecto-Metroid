#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Proyectil : public Dibujo, public Actualizable
{
private:

protected:
    int tiempoVida;

public:
    Proyectil(Vector posicion) : Dibujo(posicion.LeerX(), posicion.LeerY(), "beam")
    {
        this->tiempoVida = 15;
    }
    int Actualizar()
    {
        this->posicion.DesplazarX(1);
        this->tiempoVida --;
        return this->tiempoVida;
    }
    ~Proyectil() {}
};