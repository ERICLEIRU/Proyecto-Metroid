#pragma once
#include <Proyectil.hpp>

class Beam : public Proyectil
{
private:
    /* data */
public:
    Beam(Vector posicion): Proyectil(posicion, "beam")
     {
        this-> tiempoVida = 50; 
     }
    ~Beam() {}
};