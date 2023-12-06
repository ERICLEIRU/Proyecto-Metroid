#pragma once
#include <Dibujo.hpp>
#include <Vector.hpp>
#include <HitBox.hpp>
#include <string>

class AreaSolida : public Dibujo, public HitBox
{
private:
    /* data */
public:
    AreaSolida(int posicionX, int posicionY, string textura, int largoHitBox, int alturaHitbox) : Dibujo(posicionX, posicionY, textura, largoHitBox, alturaHitbox, 0, 0),
                                                                                                  HitBox(posicionX, posicionY, largoHitBox, alturaHitbox)
    {
    }
    void CambiarColor(int red, int green, int blue)
    {
        this->color = sf::Color(red, green, blue);
        this->sprite.setColor(this->color);
    }
    ~AreaSolida() {}
};