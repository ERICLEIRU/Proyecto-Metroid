#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

using namespace std;

class Enemigo : public Dibujo, public Actualizable, public HitBox
{
private:
protected:
    int vida;

public:
    Enemigo(int posicionX, int posicionY, int largoHitBox, int alturaHitbox, int inicioSpriteX, int inicioSpriteY) : Dibujo(posicionX, posicionY, "Enemies", largoHitBox, alturaHitbox, inicioSpriteX, inicioSpriteY), HitBox(this->posicion.LeerX(), this->posicion.LeerY(), largoHitBox, alturaHitbox)
    {
        this->posicion.AsignarX(posicionX);
        this->posicion.AsignarY(posicionY);
    }
    // Vector LeerPosicion()
    // {
    //     return this->posicion;
    // }
    void RecibirDanio(int danio)
    {
        this->vida -= danio;
    }
    int LeerVida()
    {
        return this->vida;
    }
    ~Enemigo() {}
};