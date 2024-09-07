#include "../include/Enemy.h"

Enemy::Enemy() {
    speed = 0.5;
    texturePath = "../assets/enemy.png";
    loadSprite(texturePath);

    int xPos;
    int yPos;
    if((rand() % 2) + 1 ==  2){
        if((rand() % 2) + 1 ==  2){
            xPos = -30;
        }else{
            xPos = 798;
        }
        yPos = (rand() % 576 + 1) - 30;
    }else{
        if((rand() % 2) + 1 ==  2){
            yPos = -30;
        }else{
            yPos = 606;
        }
        xPos = (rand() % 768 + 1) - 30;
    }

    sprite.setPosition(xPos, yPos);
}

void Enemy::moveObj(sf::Vector2f playerPos) {
    float enemyXPos = sprite.getPosition().x;
    float enemyYPos = sprite.getPosition().y;
    float playerXPos = playerPos.x;
    float playerYPos = playerPos.y;


    if(enemyXPos < playerXPos){
        sprite.move(speed, 0.0f);
    }else if(enemyXPos > playerXPos){
        sprite.move(-speed, 0.0f);
    }

    if(enemyYPos < playerYPos){
        sprite.move(0.0f, speed);
    }else if(enemyYPos > playerYPos){
        sprite.move(0.0f, -speed);
    }

}

void Enemy::rotateObj(sf::Vector2f playerPos) {
    sf::Vector2f spritePos = sprite.getPosition();

    float dX = playerPos.x - spritePos.x;
    float dY = playerPos.y - spritePos.y;

    float angle = (atan2(dY, dX)*180)/3.14159;
    sprite.setRotation(angle);
}