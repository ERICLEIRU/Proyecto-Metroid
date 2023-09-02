#include <string>
#include <iostream>

class mascota
{
private:
    /* data */
    int vida;
    std::string nombre;

public:
    mascota()
    {

        this->vida = 100;
    }
    ~mascota() {}
    void EstablecerNombre(std::string nombre)
    {
        this->nombre = nombre;
    }
    void DecirNombre()
    {
        std::cout << "Mi nombre es:  " << this->nombre << std::endl;
    }
};