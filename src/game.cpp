#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <Ventana.hpp>
#include <list>
#include <curses.h>

// #include <Agua.hpp>
// #include <Aire.hpp>
// #include <Animacion.hpp>
// #include <Area.hpp>
// #include <AreaSolida.hpp>
// #include <Atmosfera.hpp>
#include <Beam.hpp>
// #include <Bomb.hpp>
// #include <CargaDeEnergia.hpp>
// #include <CargaDeMisilRojo.hpp>
// #include <CargaDeMisilVerde.hpp>
// #include <Contador.hpp>
// #include <ControladorMovimiento.hpp>
#include <Crawler.hpp>
// #include <Damage.hpp>
#include <Enemigo.hpp>
// #include <Energia.hpp>
// #include <Floater.hpp>
// #include <Flyer.hpp>
// #include <HighJump.hpp>
#include <Hopper.hpp>
// #include <IceBeam.hpp>
// #include <Imagen.hpp>
// #include <Jefe.hpp>
// #include <Juego.hpp>
// #include <Jugador.hpp>
// #include <Kraid.hpp>
// #include <Lava.hpp>
// #include <LongBeam.hpp>
// #include <MaruBall.hpp>
// #include <Menu.hpp>
// #include <Misil.hpp>
// #include <MisilRojo.hpp>
// #include <MisilVerde.hpp>
// #include <MotherBrain.hpp>
// #include <MovimientoEstablecido.hpp>
// #include <ObjetoUsable.hpp>
// #include <OpcionContinuarGuardado.hpp>
// #include <OpcionGuardar.hpp>
// #include <OpcionIniciar.hpp>
// #include <OpcionMenu.hpp>
// #include <OpcionSalirPausa.hpp>
// #include <Pantalla.hpp>
// #include <PantallaInicio.hpp>
// #include <PantallaJuego.hpp>
// #include <PantallaPause.hpp>
// #include <Personaje.hpp>
// #include <Piso.hpp>
// #include <PisoDestruibleDash.hpp>
// #include <PisoDestruibleMisilRojo.hpp>
// #include <PisoDestruibleMisilVerde.hpp>
// #include <PisoFalso.hpp>
// #include <PisoQuebradiso.hpp>
// #include <PisoSolido.hpp>
// #include <Posicion.hpp>
// #include <PowerUp.hpp>
#include <Proyectil.hpp>
// #include <Puerta.hpp>
// #include <PuertaAzul.hpp>
// #include <PuertaRoja.hpp>
// #include <PuertaVerde.hpp>
// #include <Ripley.hpp>
#include <SamusAran.hpp>
// #include <ScrewAttack.hpp>
// #include <Sonido.hpp>
// #include <Swarm.hpp>
// #include <Swooper.hpp>
// #include <TanqueEnergia.hpp>
// #include <Teclado.hpp>
// #include <VariaSuit.hpp>
#include <Ventana.hpp>
// #include <WaveBeam.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    Ventana *ventana = new Ventana();
    list<Dibujo *> dibujos;
    list<Actualizable *> actualizables;
    list<Proyectil *> proyectiles;

    SamusAran *samus0 = new SamusAran(10, 10);
    dibujos.push_back(samus0);
    actualizables.push_back(samus0);
    Crawler* crawler0 = new Crawler(100,5);
    dibujos.push_back(crawler0);
    actualizables.push_back(crawler0);
    Hopper* hopper0 = new Hopper(150, 10);
    dibujos.push_back(hopper0);
    actualizables.push_back(hopper0);

    while (!ventana->DeboCerrar())
    {

        int key = getch();

        auto tempDibujos = list<Dibujo*>(dibujos);
        auto tempActualizables = list<Actualizable*>(actualizables);

        /// Arma Disparar
        if (key == 'f' || key == ' ')
        {

            Beam *p = new Beam(samus0->LeerPosicion());
            proyectiles.push_back(p);
        }

        if (!proyectiles.empty())
        {
            /// Arma Actualizar - Actualizame
            for (auto it = proyectiles.begin(); it != proyectiles.end();)
            {
                if (!(*it)->EstaVivo())
                {
                    it = proyectiles.erase(it);
                }
                else
                {
                    ++it;
                }
            }

            for (auto &&p : proyectiles)
            {
                tempDibujos.push_back(p);
                tempActualizables.push_back(p);
            }
            
        
        }

        ventana->Actualizar(tempActualizables);

       // ventana->Dibujar(tempDibujos);

        // for (auto &&iterador : actualizables)
        // {
        //     if(iterador->Actualizar() <0){
        //         actualizables.erase(iterador);
        //     }

        // }

        //  ventana.Cerrar();
    }

    return 0;
}
