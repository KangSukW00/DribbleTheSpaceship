#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(const sf::Vector2f pos, float size, sf::Color color, float speed, const Player* player)
	:position{pos}, size{size}, color{color}, speed{speed}, playerRef{player}
{
	shape = sf::CircleShape{ size };
	shape.setFillColor(color);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(1.0f);
}

Enemy::Enemy()
{

}

void Enemy::Update()
{
	UpdatePosition();
	shape.setPosition(position);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Enemy::GetPosition() const
{
	return position;
}

void Enemy::UpdatePosition()
{
	
	float enemyToPlayerX = playerRef->GetPosition().x - position.x;		//적과 나의 x차이
	float enemyToPlayerY = playerRef->GetPosition().y - position.y;		//적과 나의 y차이

	float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);
	//피타고라스정리 이요해서 두 좌표 거리를 구한것 : 루트(x의차이^2 + y의차이^2)

	enemyToPlayerX /= length;		//플레이어로 향하는 적의 벡터 크기 1짜리를 구한것
	enemyToPlayerY /= length;

	position.x += enemyToPlayerX * speed;
	position.y += enemyToPlayerY * speed;
}
