#ifndef INC_2D_SHOOTER_BULLET_H
#define INC_2D_SHOOTER_BULLET_H

#include "Base.h"

class Bullet: virtual public Base{
public:
    Bullet(sf::Vector2f playerPos, int playerRotation);

    void moveObj(sf::Vector2f);

    void rotateObj(sf::Vector2f mousePos);

    sf::Vector2f getPos();
};


#endif //INC_2D_SHOOTER_BULLET_H
