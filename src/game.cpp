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
// #include <Hopper.hpp>
// #include <Proyectil.hpp>

// #include <SamusAran.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    GestorVentana *ventana = new GestorVentana();
    Crawler *crawler0 = new Crawler(100, 5);

    while (!ventana->DeboCerrar())
    {

        ventana->Dibujar(/*dibujos*/);
    }

    // Ventana *ventana = new Ventana();
    // list<Dibujo *> dibujos;
    // list<Actualizable *> actualizables;
    // list<Proyectil *> proyectiles;

    // SamusAran *samus0 = new SamusAran(10, 10);
    // dibujos.push_back(samus0);
    // actualizables.push_back(samus0);
    // dibujos.push_back(crawler0);
    // actualizables.push_back(crawler0);
    // Hopper* hopper0 = new Hopper(150, 10);
    // dibujos.push_back(hopper0);
    // actualizables.push_back(hopper0);

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

    //     }

    //     ventana->Actualizar(tempActualizables);

    // ventana->Dibujar(tempDibujos);

    // for (auto &&iterador : actualizables)
    // {
    //     if(iterador->Actualizar() <0){
    //         actualizables.erase(iterador);
    //     }

    // }

    //  ventana.Cerrar()};

    return 0;
}
