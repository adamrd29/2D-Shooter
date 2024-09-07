#ifndef INC_2D_SHOOTER_PLAYER_H
#define INC_2D_SHOOTER_PLAYER_H
#include "Base.h"


class Player: virtual public Base{
public:
    Player();

    void moveObj(sf::Vector2f movementParams);

    void rotateObj(sf::Vector2f mousePos);

    sf::Vector2f getPos();

    float getRotation();
};



#endif //INC_2D_SHOOTER_PLAYER_H
