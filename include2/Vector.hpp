#pragma once

class Vector
{
private:
    int x, y, direccion_x, direccion_y;

public:
    Vector()
    {
        this->x = 0;
        this->y = 0;
        this->direccion_x = 1;
        this->direccion_y = 1;
    }
    Vector(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->direccion_x = 1;
        this->direccion_y = 1;
    }
    void CambiarDireccionX()
    {
        this->direccion_x *= -1;
    }
    void CambiarDireccionY()
    {
        this->direccion_y *= -1;
    }
    int LeerX()
    {
        return this->x;
    }
    int LeerY()
    {
        return this->y;
    }
    int LeerDireccionX()
    {
        return this->direccion_x;
    }
    int LeerDireccionY()
    {
        return this->direccion_y;
    }
    void DesplazarX(unsigned int x)
    {
        this->x += x * this->direccion_x;
    }
    void DesplazarY(unsigned int y)
    {
        this->y += y * this->direccion_y;
    }
    void AsignarY(unsigned int Y)
    {
        this->y = Y;
    }
    void AsignarX(unsigned int X)
    {
        this->x = X;
    }
    ~Vector() {}
};