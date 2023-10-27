#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

using namespace std;

class SamusAran : public Dibujo, public Actualizable, public HitBox
{
private:
    /* data */
public:
    SamusAran() : Dibujo("astronauta"), HitBox(this->posicion.LeerX(), this->posicion.LeerY(), 4, 5)
    {
        this->posicion = Vector();
    }
    SamusAran(int x, int y) : Dibujo("astronauta"), HitBox(this->posicion.LeerX(), this->posicion.LeerY(), 4, 5)
    {
        this->posicion.DesplazarX(x);
        this->posicion.DesplazarY(y);
    }
    int Actualizar()
    {

        this->x = this->posicion.LeerX();
        this->y = this->posicion.LeerY();

        this->posicion.DesplazarX(0);

        return 1;
    }
    void AvanzarX()
    {
        if (this->posicion.LeerDireccionX() == -1)
        {
            this->posicion.CambiarDireccionX();
        }
        this->posicion.DesplazarX(1);
    }
    void RetrocederX()
    {
        if (this->posicion.LeerDireccionX() == 1)
        {
            this->posicion.CambiarDireccionX();
        }
        this->posicion.DesplazarX(1);
    }
    void SubirY()
    {
        if (this->posicion.LeerDireccionY() == 1)
        {
            this->posicion.CambiarDireccionY();
        }
        this->posicion.DesplazarY(1);
    }
    void BajarY()
    {
        if (this->posicion.LeerDireccionY() == -1)
        {
            this->posicion.CambiarDireccionY();
        }
        this->posicion.DesplazarY(1);
    }

    Vector LeerPosicion()
    {
        return this->posicion;
    }

    ~SamusAran() {}
};