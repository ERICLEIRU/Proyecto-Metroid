#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <list>
#include <GestorVentana.hpp>
#include <SFML/Graphics.hpp>
// #include <Beam.hpp>
#include <Crawler.hpp>
#include <Enemigo.hpp>
#include <Mellow.hpp>
#include <JugadorSamus.hpp>
// #include <Hopper.hpp>
// #include <Proyectil.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    GestorVentana *ventana = new GestorVentana();
    Crawler *crawler0 = new Crawler(200, 100);
    Crawler *crawler1 = new Crawler(200, 200);
    Mellow *mellow0 = new Mellow(200, 300);
    Mellow *mellow1 = new Mellow(200, 200);
    JugadorSamus *samus0 = new JugadorSamus(400, 150);
    list<Dibujo *> dibujos;

    dibujos.push_back(crawler0);
    dibujos.push_back(crawler1);
    dibujos.push_back(mellow0);
    dibujos.push_back(mellow1);
    dibujos.push_back(samus0);
    list<Actualizable *> actualizables;
    actualizables.push_back(crawler0);
    actualizables.push_back(crawler1);
    actualizables.push_back(mellow0);
    actualizables.push_back(mellow1);
    actualizables.push_back(samus0);

    while (!ventana->DeboCerrar())
    {
        ventana->Dibujar(dibujos);
        ventana->JugadorEnFondoX(samus0->llegoFondoX());
        for (auto &&actual : actualizables)
        {
            actual->Actualizar();
        }
    }

    // Ventana *ventana = new Ventana();
    //
    // list<Proyectil *> proyectiles;

    // while (!ventana->DeboCerrar())
    // {

    //     int key = getch();

    //     auto tempDibujos = list<Dibujo*>(dibujos);
    //     auto tempActualizables = list<Actualizable*>(actualizables);

    //     /// Arma Disparar
    //     if (key == 'f' || key == ' ')
    //     {

    //         Beam *p = new Beam(samus0->LeerPosicion());
    //         proyectiles.push_back(p);
    //     }

    //     if (!proyectiles.empty())
    //     {
    //         /// Arma Actualizar - Actualizame
    //         for (auto it = proyectiles.begin(); it != proyectiles.end();)
    //         {
    //             if (!(*it)->EstaVivo())
    //             {
    //                 it = proyectiles.erase(it);
    //             }
    //             else
    //             {
    //                 ++it;
    //             }
    //         }

    //         for (auto &&p : proyectiles)
    //         {
    //             tempDibujos.push_back(p);
    //             tempActualizables.push_back(p);
    //         }

    return 0;
}
