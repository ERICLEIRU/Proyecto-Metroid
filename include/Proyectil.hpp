#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Proyectil : public Dibujo, public Actualizable
{
private:
protected:
    int tiempoVida;

public:
    Proyectil(Vector posicion, string txtName) : Dibujo(posicion.LeerX()+2, posicion.LeerY()+1, txtName)
    {
        this->tiempoVida = 15;
    }
    void Actualizar()
    {
        this->posicion.DesplazarX(1);
        this->tiempoVida--;
    }
    bool EstaVivo()
    {
        return this->tiempoVida > 0;
    }
    ~Proyectil() {}
};