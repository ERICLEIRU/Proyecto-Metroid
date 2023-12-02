#pragma once

class HitBox
{
private:
protected:
    unsigned int xHitBox;
    unsigned int yHitBox;
    unsigned int dxHitBox;
    unsigned int dyHitBox;

public:
    HitBox(unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
    {

        this->xHitBox = x;
        this->yHitBox = y;
        this->dxHitBox = dx;
        this->dyHitBox = dy;
    }

    bool DetectarColision(HitBox *hitBox)
    {
        // Calculos para hitbox
        int der1 = this->xHitBox + this->dxHitBox;
        int izq1 = this->xHitBox;

        int der2 = hitBox->xHitBox + hitBox->dxHitBox;
        int izq2 = hitBox->xHitBox;

        if ((izq1 < der2 && izq1 > izq2) || (der1 > izq2 && der1 < der2))
        {
            return true;
        }

        return false;
    }
    ~HitBox() {}
};