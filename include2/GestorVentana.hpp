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
    sf::RectangleShape fondo;

public:
    GestorVentana(/* args */)
    {
        this->window.create(sf::VideoMode(800, 600), "Metroid");
        window.setFramerateLimit(360);
        sf::Event event;
        fondo.setSize(sf::Vector2f(800, 800));
        fondo.setFillColor(sf::Color(115, 115, 115));
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
        this->window.draw(fondo);
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
