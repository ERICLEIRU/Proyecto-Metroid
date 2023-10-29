#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ControladorMovimiento.hpp>
#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

using namespace std;

class SamusAran : public Dibujo, public Actualizable, public HitBox, public ControladorMovimiento
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
    void Actualizar()
    {

        this->xHitBox = this->posicion.LeerX();
        this->yHitBox = this->posicion.LeerY();
        this->ControlarMovimiento();

        this->posicion.DesplazarX(0);

    
    }
    void ControlarMovimiento(){
            int key = getch();

        if (key == 'a' || key == KEY_LEFT)
        {
            this->RetrocederX();
        }
        if (key == 'd' || key == KEY_RIGHT)
        {
            this->AvanzarX();
        }
        if (key == 'w' || key == KEY_UP)
        {
            this->SubirY();
        }
        if (key == 's' || key == KEY_DOWN)
        {
            this->BajarY();
        }
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