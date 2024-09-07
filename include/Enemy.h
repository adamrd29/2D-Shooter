#ifndef INC_2D_SHOOTER_ENEMY_H
#define INC_2D_SHOOTER_ENEMY_H

#include <stdlib.h>
#include "Base.h"


class Enemy : virtual public Base {

public:
    Enemy();

    void moveObj(sf::Vector2f playerPos);

    void rotateObj(sf::Vector2f playerPos);
};


#endif //INC_2D_SHOOTER_ENEMY_H
