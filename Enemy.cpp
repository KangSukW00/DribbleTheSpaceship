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
	
	float enemyToPlayerX = playerRef->GetPosition().x - position.x;		//���� ���� x����
	float enemyToPlayerY = playerRef->GetPosition().y - position.y;		//���� ���� y����

	float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);
	//��Ÿ������� �̿��ؼ� �� ��ǥ �Ÿ��� ���Ѱ� : ��Ʈ(x������^2 + y������^2)

	enemyToPlayerX /= length;		//�÷��̾�� ���ϴ� ���� ���� ũ�� 1¥���� ���Ѱ�
	enemyToPlayerY /= length;

	position.x += enemyToPlayerX * speed;
	position.y += enemyToPlayerY * speed;
}
