#ifndef INC_2D_SHOOTER_BASE_H
#define INC_2D_SHOOTER_BASE_H
#include <SFML/Graphics.hpp>
#include <valarray>


class Base {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f origin;
    std::string texturePath;
    float speed;

public:
    virtual ~Base();

    void loadSprite(std::string texturePath);

    void drawObj(sf::RenderWindow &window);

    sf::FloatRect getHitbox() const;

    virtual void moveObj(sf::Vector2f)=0;

    virtual void rotateObj(sf::Vector2f)=0;



};


#endif //INC_2D_SHOOTER_BASE_H
