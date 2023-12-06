#pragma once
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <Vector.hpp>
using namespace std;

class Dibujo
{
private:
    bool is_open;
    string directorio;

protected:
    Vector posicion;
    sf::Texture textura;
    sf::Sprite sprite;
    sf::IntRect intRect;
    sf::Color color;

public:
    Dibujo(int posicionX, int posicionY, string recurso, int largoHitBox, int alturaHitbox, int inicioSpriteX, int inicioSpriteY)
    {

        this->directorio = "./imagenes/" + recurso + ".png";
        this->posicion = Vector(posicionX, posicionY);
        this->textura.loadFromFile(directorio);
        this->sprite.setTexture(textura);
        this->intRect = sf::IntRect(inicioSpriteX, inicioSpriteY, largoHitBox, alturaHitbox);
        this->sprite.setTextureRect(intRect);
        this->color = sf::Color(0, 255, 0);
        // this->sprite.setColor(color);
        this->sprite.setPosition(posicionX, posicionY);
    }
    Dibujo(string recurso) : Dibujo(0, 0, recurso, 0, 0, 0, 0)
    {
    }
    sf::Sprite MandarSprite()
    {
        return this->sprite;
    }
    ~Dibujo()
    {
    }
};
