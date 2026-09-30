#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Weapons.h"


class Player {
public:
	Player(sf::Vector2f v, sf::Texture pT, sf::Sprite pS);
	virtual void update(float dt);
	bool collision(sf::Sprite& eS);
	void draw(sf::RenderWindow& w);
	void move(float dt);
	void jump();
	void attack();
	virtual void getHit(int& dmg);
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
	bool seeWeapon;
	bool rightSight;
	Weapons playerWeapon;
	

};