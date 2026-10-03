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
	bool attack();
	bool getFacing();
	virtual void getHit(int& dmg);
	float getXPosition();
	Weapons& getWeapon();
protected:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f Velocity;
	sf::Clock dmgTime;
	sf::Clock releaseTime;
	float gravity = 950.f;
	float attackTimer = 0;
	float attackDuration = 0.3f;;
	float iFrames = 0.5f;
	int health = 100;
	int damage = 10;
	int weaponAngle;
	bool inAir;
	bool seeWeapon;
	bool rightSight;
	bool isAttacking;
	Weapons playerWeapon;
};