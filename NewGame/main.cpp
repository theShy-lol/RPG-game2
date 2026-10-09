#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Player.h"
#include"Terrain.h"
#include"Enemy.h"
#include"Weapons.h"
#include"Obstacle.h"



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
	sf::Texture t;
	sf::Sprite s;
	//Entities
	int playerHealth = 100;
	int enemieOneHealth = 100;
	int enemieTwoHealth = 150;
	int enemieThreeHealth = 200;
	Player player(velocity, t, s,playerHealth);
	Enemy enemy(t, s, velocity,enemieOneHealth);
	Enemy enemy2(t, s, velocity,enemieTwoHealth);
	Enemy enemy3(t, s, velocity, enemieThreeHealth);
	Weapons weapon;
	std::vector <Enemy> enemies = { enemy, enemy2, enemy3 };
	
	//WorldDesign
	Terrain terrain(100);
	Obstacle obstacle;
	//Main loop
	while (window.isOpen()) {
		camera.setCenter(sf::Vector2f(player.getXPosition(), SCREEN_HEIGHT / 2));
		sf::Event event;
		dt = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (camera.getCenter().x < SCREEN_WIDTH / 2) {
			camera.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		}
		window.setView(camera);
		player.move();
		player.jump();
		enemy.die();
		enemy.move();
		player.attack();
		player.update(dt);
		enemy.update(dt);
		player.checkObstacleCol(obstacle.getObstacle());
		if (player.collision(enemy.getEnemy()) == true) {
			player.getHit(enemy.enemyDmg());
		}
		if (enemy.collisionEnemy(player.getWeapon(), player) == true) {
			enemy.getHit(weapon.getDamage());
		}
		window.clear(sf::Color::Black);
		terrain.drawTerrain(window);
		obstacle.straightObstacle(10);
		obstacle.stairsObstacle(5);
		obstacle.decreaseObstacle(7);
		obstacle.drawObstacle(window);
		player.draw(window);
		enemy.draw(window);
		window.display();
	}
}