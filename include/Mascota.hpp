#include <string>
#include <iostream>

class Mascota
{
private:
    /* data */
    int vida;
    std::string nombre;

public:
    Mascota()
    {
        this->vida = 100;
    }
    ~Mascota() {}
    void EstablecerNombre(std::string nombre)
    {
        this->nombre = nombre;
    }
    void DecirNombre()
    {
        std::cout << "Mi nombre es:  " << this->nombre << std::endl;
    }
};