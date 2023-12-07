#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

using namespace std;

class Personaje : public Dibujo, public Actualizable, public HitBox
{
private:
protected:
    int vida;

public:
    Personaje(int posicionX, int posicionY, int largoHitBox, int alturaHitbox, int inicioSpriteX, int inicioSpriteY) : Dibujo(posicionX, posicionY, "SamusPowerSuit-NoBackGround", largoHitBox, alturaHitbox, inicioSpriteX, inicioSpriteY), HitBox(this->posicion.LeerX(), this->posicion.LeerY(), largoHitBox, alturaHitbox)
    {
        this->posicion.AsignarX(posicionX);
        this->posicion.AsignarY(posicionY);
    }
    void RecibirDanio(int danio)
    {
        this->vida -= danio;
    }
    int LeerVida()
    {
        return this->vida;
    }
    ~Personaje() {}
};