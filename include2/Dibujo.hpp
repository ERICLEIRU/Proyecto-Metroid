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

public:
    Dibujo(int x, int y, string recurso)
    {

        this->directorio = "./imagenes/" + recurso + ".png";
        this->posicion = Vector(x, y);
        this->textura.loadFromFile(directorio);
    }
    Dibujo(string recurso) : Dibujo(0, 0, recurso)
    {
    }
    sf::Texture MandarTextura()
    {
        return textura;
    }
    ~Dibujo()
    {
        // archivo.close();
    }
};