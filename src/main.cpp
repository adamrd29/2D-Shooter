#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"

int main(){
    //initialise variables
    int score  = 0;
    int health = 5;
    int firerate = 30;
    sf::Vector2f movementParams;

    //create vectors for storing objects
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;

    // create the window
    sf::RenderWindow window(sf::VideoMode(768, 576), "2D Shooter", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event event;

    //Load Background
    sf::Texture backgroundSprite;
    if(!backgroundSprite.loadFromFile("../assets/background.png")){
        throw std::runtime_error("Failed to load sprite");
    }

    //health bar
    sf::RectangleShape healthContainer(sf::Vector2f(254,20));
    healthContainer.setPosition(10,10);
    healthContainer.setFillColor(sf::Color{0,0,0,200});

    //Score
    sf::Font font;
    if (!font.loadFromFile("../fonts/Pixeloid.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }
    sf::Text scoreText;
    scoreText.setFont(font);


    //Background Initialisation
    sf::Sprite background(backgroundSprite);

    //initialise player object
    Player player;

    //begin game loop
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            //Close window when 'X' clicked
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        //Score
        std::string scoreString = "Score: " + std::to_string(score*100);
        scoreText.setString(scoreString);
        scoreText.setPosition(570,0);

        //Health Bar
        sf::RectangleShape healthBar(sf::Vector2f((50 * health),16));
        healthBar.setPosition(12,12);
        healthBar.setFillColor(sf::Color{0,255,0,200});

        //Player Movement
        movementParams.x = 0;
        movementParams.y = 0;
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && player.getPos().x >= 20){
            movementParams.x = -1.0;

        } else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && player.getPos().x <= 738){
            movementParams.x = 1.0;
        }

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && player.getPos().y >= 20){
            movementParams.y = -1.0;
        } else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) && player.getPos().y <= 546){
            movementParams.y = 1.0;
        }

        player.moveObj(movementParams);
        sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        player.rotateObj(mousePositionFloat);
        sf::FloatRect playerBounds = player.getHitbox();

        //Enemy Spawning
        if((rand()%1000) <= 10 + score/2){
            enemies.push_back(new Enemy);
        }

        //Bullet Spawning
        firerate--;
        if(firerate == 0){
            bullets.push_back(new Bullet(player.getPos(), player.getRotation()));
            firerate = 30;
        }

        //enemy collision detection and deletion
        for(int i=0; i<enemies.size(); i++){
            sf::FloatRect enemyBounds = enemies[i]->getHitbox();
            for(int j=0; j<bullets.size();){
                sf::FloatRect bulletBounds = bullets[j]->getHitbox();
                if(bulletBounds.intersects(enemyBounds)){
                    enemies.erase(enemies.begin() + i);
                    bullets.erase(bullets.begin() + j);
                    score += 1;
                }else if(bullets[j]->getPos().x > 750 || bullets[j]->getPos().y > 600 || bullets[j]->getPos().x < -30 || bullets[j]->getPos().y < -30){
                    bullets.erase(bullets.begin() + j);
                }else{
                    j++;
                }
            }

            //Stop Enemy stacking
            int enemyCollisions = 0;
            for(int k=0; k<enemies.size();k++){
                sf::FloatRect enemyBounds2 = enemies[k]->getHitbox();
                if(enemyBounds2.intersects(enemyBounds)){
                     enemyCollisions++;
                     if(enemyCollisions < 2){
                         enemies[i]->moveObj(player.getPos());
                     }
                }
            }

            //Player-Enemy collision control
            if(playerBounds.intersects(enemyBounds)){
                health--;
                enemies.erase(enemies.begin() + i);
                if(health < 1){
                    window.close();
                }
            }

        }

        //Clear window
        window.clear();

        window.draw(background);

        player.drawObj(window);

        //loop through enemies
        for(int i=0; i<enemies.size(); i++){
            enemies[i]->rotateObj(player.getPos());
            enemies[i]->drawObj(window);
        }

        for(int i=0; i<bullets.size(); i++){
            bullets[i]->moveObj(sf::Vector2f());
            bullets[i]->rotateObj(player.getPos());
            bullets[i]->drawObj(window);
        }

        window.draw(scoreText);
        window.draw(healthContainer);
        window.draw(healthBar);

        window.display();
    }

    return 0;
}