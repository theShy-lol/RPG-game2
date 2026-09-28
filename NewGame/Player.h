#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Weapons.h"


class Player {
public:
	Player(sf::Vector2f v, sf::Texture pT, sf::Sprite pS);
	virtual void update(float dt);
	void collision(sf::Sprite& eS);
	void draw(sf::RenderWindow& w);
	void move(float dt);
	void jump();
	void attack();
	float getXPosition();
protected:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f Velocity;
	float gravity = 950.f;
	int health = 100;
	int damage = 10;
	sf::Clock dmgTime;
	float iFrames = 0.5f;
	bool inAir;
	Weapons playerWeapon;

};