#include <iostream>
#include <mascota.hpp>

int main(int argc, char const *argv[])
{
    std::cout << "Juego de mascotas " << std::endl;

    mascota m1,m2, m3; //Se estan creando tres instancias, las instancias van en minuscula camelCase

    //hay tres tipos de mendajes entrada, salida, entrada-salida,
    m1.EstablecerNombre("Perruno");
    m2.EstablecerNombre("Tripode");
    m3.EstablecerNombre("Ciclope");
    m1.DecirNombre();
    m2.DecirNombre();
    m3.DecirNombre();

    return 0;
}
