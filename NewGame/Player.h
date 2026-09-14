#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>


class Player {
public:
	Player(sf::Vector2f v, sf::Texture pT, sf::Sprite pS);
	virtual void update(float dt);
	void collision( sf::Sprite& eS);
	void draw(sf::RenderWindow& w);
	void move(float dt);
	void jump();
	float getXPosition();
protected:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f Velocity;
	float gravity = 950.f;
	int health = 100;
	bool inAir;

};