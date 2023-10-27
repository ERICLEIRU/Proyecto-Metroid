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
// #include <Crawler.hpp>
// #include <Damage.hpp>
// #include <Enemigo.hpp>
// #include <Energia.hpp>
// #include <Floater.hpp>
// #include <Flyer.hpp>
// #include <HighJump.hpp>
// #include <Hopper.hpp>
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

    SamusAran *samus0 = new SamusAran(10, 10);
    dibujos.push_back(samus0);
    actualizables.push_back(samus0);

    while (!ventana->DeboCerrar())
    {
        int key = getch();

        if (key == 'a' || key == KEY_LEFT)
        {
            samus0->RetrocederX();
        }
        if (key == 'd' || key == KEY_RIGHT)
        {
            samus0->AvanzarX();
        }
        if (key == 'w' || key == KEY_UP)
        {
            samus0->SubirY();
        }
        if (key == 's' || key == KEY_DOWN)
        {
            samus0->BajarY();
        }
        if (key == 'f' || key == ' ')
        {

            Beam *p = new Beam(samus0->LeerPosicion());
            dibujos.push_back(p);
            actualizables.push_back(p);
        }

        ventana->Dibujar(dibujos);
        ventana->Actualizar(actualizables);

        // for (auto &&iterador : actualizables)
        // {
        //     if(iterador->Actualizar() <0){
        //         actualizables.pop_back();
        //     }
            
        // }

        //  ventana.Cerrar();
    }

    return 0;
}
