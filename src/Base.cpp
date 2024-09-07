#include "../include/Base.h"

Base::~Base(){}

void Base::loadSprite(std::string texturePath){
        if(!texture.loadFromFile(texturePath)){
            throw std::runtime_error("Failed to load sprite");
        }
        sprite.setTexture(texture);
        //sprite.setTextureRect(sf::IntRect(0,0,59,45));
        auto bounds = sprite.getLocalBounds();
        origin = sf::Vector2f(bounds.width/2, bounds.height/2);
        sprite.setOrigin(origin);
};


void Base::drawObj(sf::RenderWindow &window){
    window.draw(sprite);
};

sf::FloatRect Base::getHitbox() const{
    return sprite.getGlobalBounds();
}
