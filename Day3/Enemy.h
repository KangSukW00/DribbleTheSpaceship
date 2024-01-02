#pragma once

#include <SFML/Graphics.hpp>

class Player;

class Enemy
{
public:
    Enemy(const sf::Vector2f pos, float size, sf::Color color, float speed,
        const Player* player);
    Enemy();

    void Update();  //µ¿ÀÛ

    void Draw(sf::RenderWindow& window);    //±×¸®±â

    sf::Vector2f GetPosition() const;

private:
    void UpdatePosition();

private:
    sf::Vector2f position;
    float speed;
    const Player* playerRef;

    sf::CircleShape shape;
    float size;
    sf::Color color;
};
