#include "../include/Bullet.h"

Bullet::Bullet(sf::Vector2f playerPos, int playerRotation) {
    speed = 10;
    texturePath = "../assets/bullet.png";
    loadSprite(texturePath);
    sprite.setPosition(playerPos);
    sprite.setRotation(playerRotation);
    float radians = sprite.getRotation() * (3.14159/180);
    sprite.move(40*cos(radians), 40*sin(radians));
}

void Bullet::moveObj(sf::Vector2f){
    float radians = sprite.getRotation() * (3.14159/180);
    sprite.move(speed*cos(radians), speed*sin(radians));
}

void Bullet::rotateObj(sf::Vector2f playerPos){
    return;
}

sf::Vector2f Bullet::getPos() {
    return sprite.getPosition();
}