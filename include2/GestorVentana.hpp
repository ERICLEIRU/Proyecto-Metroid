#pragma once
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <Dibujo.hpp>
// #include <Actualizable.hpp>
#include <list>

using namespace std;

class GestorVentana
{
private:
    /* data */
    int x, y;
    bool cerrar;

protected:
    sf::RenderWindow window;
    sf::Event event;

public:
    GestorVentana(/* args */)
    {
        this->window.create(sf::VideoMode(1000, 800), "Metroid");
        sf::Event event;
    }
    void Actualizar(/*list<Actualizable *> listaActualizables*/)
    {
        /*
        for (auto &&iterador : listaActualizables)
        {
            iterador->Actualizar();
        }
        usleep(41000);
        */
    }
    void Dibujar(list<Dibujo *> listaDibujos)
    {
        this->window.clear();
        for (auto &&dibujo : listaDibujos)
        {
            this->window.draw(dibujo->MandarSprite());
        }
        this->window.display();
    }
    bool DeboCerrar()
    {
        while (this->window.pollEvent(event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window.close();
        }

        return !this->window.isOpen();
    }
    void Cerrar()
    {
        this->window.close();
    }
    ~GestorVentana()
    {
        this->window.close();
    }
};
