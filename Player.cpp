#include "Player.h"

Player::Player(sf::Vector2f pos, float size, sf::Color color, float speed)
	: position(pos), size(size), color(color), speed{speed}
{
		shape = sf::RectangleShape(sf::Vector2f{ size, size });
		shape.setFillColor(color);
}
void Player::Update()	//플레이어의 동작
{
	ProcessInput();
	shape.setPosition(position);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Player::GetPosition() const
{
	return position;
}

void Player::ProcessInput()		//입력 처리
{
	bool dPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool aPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool sPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	bool leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	bool downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	if (dPressed || rightPressed) {
		position.x += speed;
	}
	if (aPressed || leftPressed) {
		position.x -= speed;
	}
	if (wPressed || upPressed) {
		position.y -= speed;
	}
	if (sPressed || downPressed) {
		position.y += speed;
	}
}
