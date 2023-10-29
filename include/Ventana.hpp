#pragma once
#include <curses.h>
#include <unistd.h>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <list>

using namespace std;

class Ventana
{
private:
    /* data */
    int x, y;
    bool cerrar;

public:
    Ventana(/* args */)
    {
        // Inicializar pantalla
        initscr();

        // Eliminar cursor de pantalla
        noecho();
        curs_set(FALSE);

        // no bloquear consola al momento de leer caracteres
        cbreak();
        timeout(10);
        keypad(stdscr, TRUE);

        // Inicializar clase
        getmaxyx(stdscr, y, x); // obtiene el tamaño de caracteres en pantalla
        cerrar = false;
    }
    void Actualizar(list<Actualizable *> listaActualizables)
    {
        for (auto &&iterador : listaActualizables)
        {
            iterador->Actualizar();
        }
        usleep(21000);

        // sleep(5);
    }

    void Dibujar(list<Dibujo *> listaDibujos)
    {
        clear();
        box(stdscr, 'Q', 'W');

        for (auto &&dibujo : listaDibujos)
        {
            dibujo->Dibujar();
        }

        refresh();
    }
    bool DeboCerrar()
    {
        return this->cerrar;
    }
    void Cerrar()
    {
        this->cerrar = true;
    }
    ~Ventana()
    {
        keypad(stdscr, FALSE);
        endwin();
    }
};