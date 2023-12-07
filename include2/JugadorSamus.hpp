#pragma once
#include <Personaje.hpp>
#include <Actualizable.hpp>
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>

class JugadorSamus : public Personaje
{
private:
    bool llegofondoX = 0;
    bool llegofondoY = 0;
    bool llegoinicioX = 0;
    bool llegoinicioY = 0;

public:
    JugadorSamus(int posicionInicioX, int posicionInicioY) : Personaje(posicionInicioX, posicionInicioY, 15, 32, 2, 68)
    {
        this->vida = 100;
    }
    void Actualizar()
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (this->posicion.LeerDireccionY() == 1)
            {
                this->posicion.CambiarDireccionY();
            }
            if (this->posicion.LeerY() > 1)
            {
                this->posicion.DesplazarY(1);
            }
            else
            {
                llegoinicioY = 1;
            }

            this->intRect.top = 16;
            this->intRect.left = 142;
            this->sprite.setTextureRect(intRect);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (this->posicion.LeerDireccionY() == -1)
            {
                this->posicion.CambiarDireccionY();
            }
            if (this->posicion.LeerY() < 270)
            {
                this->posicion.DesplazarY(1);
            }
            else
            {
                llegofondoY = 1;
            }
            this->intRect.top = 121;
            this->intRect.left = 129;
            this->sprite.setTextureRect(intRect);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (this->posicion.LeerDireccionX() == 1)
            {
                this->posicion.CambiarDireccionX();
            }
            if (this->posicion.LeerX() > 1)
            {
                this->posicion.DesplazarX(1);
            }
            else
            {
                llegoinicioX = 1;
            }
            this->intRect.top = 191;
            this->intRect.left = 204;
            this->sprite.setTextureRect(intRect);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (this->posicion.LeerDireccionX() == -1)
            {
                this->posicion.CambiarDireccionX();
            }
            if (this->posicion.LeerX() < 785)
            {
                this->posicion.DesplazarX(1);
            }
            else
            {
                llegofondoX = 1;
            }
            this->intRect.top = 11;
            this->intRect.left = 2;
            this->sprite.setTextureRect(intRect);
        }
        this->xHitBox = this->posicion.LeerX();
        this->yHitBox = this->posicion.LeerY();
        this->sprite.setPosition(this->posicion.LeerX(), this->posicion.LeerY());
    }
    int llegoFondoX()
    {
        if (llegofondoX)
        {
            llegofondoX = 0;
            return 1;
        }
        return 0;
    }
    ~JugadorSamus() {}
};