#pragma once
#include <Personaje.hpp>
#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

class JugadorSamus : public Personaje
{
private:
    /* data */
public:
    JugadorSamus(int posicionInicioX, int posicionInicioY) : Personaje(posicionInicioX, posicionInicioY, 15, 32, 2, 68)
    {
        this->vida = 100;
    }
    void Actualizar()
    {

        this->xHitBox = this->posicion.LeerX();
        this->yHitBox = this->posicion.LeerY();

        this->posicion.DesplazarX(1);
    }
    ~JugadorSamus() {}
};