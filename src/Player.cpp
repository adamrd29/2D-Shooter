#include "../include/Player.h"
#include <tuple>

Player::Player(){
    speed = 1.5;
    texturePath = "../assets/player.png";
    loadSprite(texturePath);
    sprite.setOrigin(17, 22);
    sprite.setPosition(384, 288);
}

void Player::moveObj(sf::Vector2f movementParams){
    sprite.move(speed*movementParams.x, speed*movementParams.y);
}

void Player::rotateObj(sf::Vector2f mousePos){
    sf::Vector2f spritePos = sprite.getPosition();

    float dX = mousePos.x - spritePos.x;
    float dY = mousePos.y - spritePos.y;

    float angle = (atan2(dY, dX)*180)/3.14159;
    sprite.setRotation(angle);
}

sf::Vector2f Player::getPos(){
    return sprite.getPosition();
}

float Player::getRotation(){
    return sprite.getRotation();
}