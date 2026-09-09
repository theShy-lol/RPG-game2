#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>


class Player {
public:
	Player(sf::Vector2f v);
	void update(float dt);
	void draw(sf::RenderWindow& w);
	void move(float dt);
	void jump();
private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f Velocity;
	float gravity = 950.f;
	bool inAir;
};