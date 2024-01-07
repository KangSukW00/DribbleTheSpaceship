#include "Player.h"


Player::Player(const sf::Vector2f pos, float size, sf::Color color, float speed)
	: position{ pos }, size{ size }, color{ color }, speed{ speed }
{
	shape = sf::RectangleShape{ sf::Vector2f{size, size} };
	shape.setFillColor(color);
}

void Player::Update(float dt)
{
	ProcessInput(dt);
	shape.setPosition(position);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}


void Player::ProcessInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		position.x -= speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		position.x += speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		position.y -= speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		position.y += speed * dt;
	}
}
