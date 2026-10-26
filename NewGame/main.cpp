#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Player.h"
#include"Terrain.h"
#include"Enemy.h"
#include"Weapons.h"
#include"Obstacle.h"
#include"EnemySpawn.h"


int main() {
	//Window
	sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH,SCREEN_HEIGHT }),"RPG");
	sf::Clock clock;
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	//Camera
	sf::View camera(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	//Relative movement
	sf::Vector2f velocity(250.f, 250.f);
	float dt = 0;
	bool inAir = false;
	//Entities
	int playerHealth = 100;
	int enemieOneHealth = 100;
	int enemieTwoHealth = 150;
	int enemieThreeHealth = 200;
	Player player(velocity,playerHealth);
	Enemy enemy(velocity,enemieOneHealth);
	Weapons weapon;
	
	//WorldDesign
	Terrain terrain(100);
	Obstacle obstacle;
	EnemySpawner enemies(800.f, GROUND_POSITION / 6);
	//Main loop
	while (window.isOpen()) {
		camera.setCenter(sf::Vector2f(player.getXPosition(), SCREEN_HEIGHT / 2));
		sf::Event event;
		dt = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || player.die()) {
				window.close();
			}
		}
		if (camera.getCenter().x < SCREEN_WIDTH / 2) {
			camera.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		}
		window.setView(camera);
		player.move();
		player.jump();
		player.attack();
		player.die();
		player.update(dt, terrain.getGaps());
		enemies.SpawnUpdate(dt, player, weapon,obstacle.getObstacle(), terrain.getGaps());
		player.checkObstacleCol(obstacle.getObstacle());
		window.clear(sf::Color::Black);
		terrain.drawTerrain(window);
		obstacle.straightObstacle(10);
		obstacle.stairsObstacle(5);
		obstacle.decreaseObstacle(7);
		obstacle.drawObstacle(window);
		player.draw(window);
		enemies.drawEnemies(window);
		window.display();
	}
}