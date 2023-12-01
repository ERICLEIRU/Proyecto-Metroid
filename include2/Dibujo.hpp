#pragma once
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <Vector.hpp>
using namespace std;

class Dibujo : public sf::Texture
{
private:
    fstream archivo; // ImagenCowASCII, ImagenCowRunASCII, ImagenCowJumpASCII;
    bool is_open;
    string directorio;

protected:
    Vector posicion;

public:
    Dibujo(int x, int y, string recurso)
    {

        this->directorio = "./imagenes/" + recurso + ".txt";
        this->is_open = false;
        this->archivo.open(this->directorio, ios::in);
        this->posicion = Vector(x, y);
    }
    Dibujo(string recurso) : Dibujo(0, 0, recurso)
    {
    }
    void Dibujar()
    {

        if (archivo.is_open())
        {

            string line;
            move(
                this->posicion.LeerY(),
                this->posicion.LeerX());

            while (getline(archivo, line))
            {

                int y;
                y = getcury(stdscr);
                mvaddstr(y + 1, this->posicion.LeerX(), line.c_str());
            }
            archivo.clear();
            archivo.seekg(0); // recetea el cursor a la posicion 0 del archivo
        }
    }
    ~Dibujo()
    {
        archivo.close();
    }
};