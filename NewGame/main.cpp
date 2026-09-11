#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Player.h"
#include"Terrain.h"
#include"Enemy.h"

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
	Player player(velocity, t, s);
	Terrain terrain(100);
	Enemy enemy(t, s, velocity);

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
		player.move(dt);
		player.jump();
		player.update(dt);
		window.clear(sf::Color::Black);
		terrain.drawTerrain(window);
		player.draw(window);
		enemy.draw(window);
		window.display();
	}
}