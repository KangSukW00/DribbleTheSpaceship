#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#else
#define DBG_NEW new
#endif

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"





int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(2508); // 누수가 있는 경우 할당 번호로 중단 설정
	

	int screenWidth = 800;
	int screenHeight = 450;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game!");
	window.setFramerateLimit(60);

	//Player
	Player player = Player{ sf::Vector2f{ 50.0f, 50.0f}, 20.0f, sf::Color::Red, 2.0f };
	
	

	//Enemies
	const int enemyCount = 10;
	Enemy* enemies = new Enemy[enemyCount];
	const sf::Color enemyColor = sf::Color{ 200, 150, 255, 255 };
	for (int i = 0; i < enemyCount; i++)
	{
		float enemyRandomX = screenWidth - 100;
		float enemyRandomY = rand() % screenHeight;
		sf::Vector2f enemyPos{ enemyRandomX, enemyRandomY };

		enemies[i] = Enemy{ enemyPos, 10.0f, sf::Color::Cyan, 0.05f, &player };
	}



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//플레이어 이동 로직
		player.Update();

		//적 이동 로직
		for (int i = 0; i < enemyCount; i++) {
			enemies[i].Update();
		}

		window.clear();		//1)지우기
		{
			player.Draw(window);

			for (int i = 0; i < enemyCount; i++) {
				enemies[i].Draw(window);
			}
		}
		window.display();	//3)표시하기

	}
	delete[] enemies;

	return 0;
}
