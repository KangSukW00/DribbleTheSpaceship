#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Vector2f pos, float size, sf::Color color, float speed);

	void Update();	//플레이어의 동작

	void Draw(sf::RenderWindow& window);	// 플레이어 그리기

	sf::Vector2f GetPosition() const;
private:
	void ProcessInput();	//키보드 입력 처리

private:

	sf::Vector2f position; //위치
	float speed;	//속도

	sf::RectangleShape shape;	//모양
	float size;	//크기
	sf::Color color;	//색깔
};
