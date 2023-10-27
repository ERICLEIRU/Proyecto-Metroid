#pragma once

class HitBox
{
private:
protected:
    unsigned int x;
    unsigned int y;
    unsigned int dx;
    unsigned int dy;

public:
    HitBox(unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
    {

        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
    }

    bool DetectarColision(HitBox *hitBox)
    {
        // Calculos para hitbox
        int der1 = this->x + this->dx;
        int izq1 = this->x;

        int der2 = hitBox->x + hitBox->dx;
        int izq2 = hitBox->x;

        if ((izq1 < der2 && izq1 > izq2) || (der1 > izq2 && der1 < der2))
        {
            return true;
        }

        return false;
    }
    ~HitBox() {}
};