#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Player.h"

int main() {
	//Window
	sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH,SCREEN_HEIGHT }),"RPG");
	sf::Clock clock;
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	//Relative movement
	sf::Vector2f velocity(250.f, 250.f);
	float dt = 0;
	bool inAir = false;
	//Entities
	Player player(velocity);

	//Main loop
	while (window.isOpen()) {
		sf::Event event;
		dt = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		player.move(dt);
		player.jump();
		player.update(dt);
		window.clear(sf::Color::Black);
		player.draw(window);
		window.display();
	}
}