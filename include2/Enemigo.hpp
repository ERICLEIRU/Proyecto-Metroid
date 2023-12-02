#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

using namespace std;

class Enemigo: public Dibujo, public Actualizable, public HitBox
{
private:

protected:

    int vida;
public:
    Enemigo(int posicionX, int posicionY, string nombreDibujo, int largoHitBox, int alturaHitbox ):
     Dibujo(nombreDibujo), 
     HitBox(this->posicion.LeerX(), this->posicion.LeerY(), largoHitBox, alturaHitbox)
    {
        this->posicion.DesplazarX(posicionX);
        this->posicion.DesplazarY(posicionY);
        this->posicion.CambiarDireccionX();
    }
        Vector LeerPosicion()
    {
        return this->posicion;
    }
        void Actualizar()
    {

        this->xHitBox = this->posicion.LeerX();
        this->yHitBox = this->posicion.LeerY();

        this->posicion.DesplazarX(1);

    
    }
    ~Enemigo() {}
};