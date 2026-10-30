#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Weapons.h"


class Player {
public:
	Player(sf::Vector2f v, int h);
	virtual void update(float dt);
	bool collision(sf::Sprite& eS);
	void draw(sf::RenderWindow& w);
	virtual void move();
	void jump();
	bool checkObstacleCol(std::vector<sf::RectangleShape>& obs);
	bool checkTerrainCol(std::vector<sf::RectangleShape>& obs);
	bool die();
	bool attack();
	virtual void getHit(int& dmg);
	void isFalling(std::vector<sf::RectangleShape>& terrain, std::vector<sf::RectangleShape>& obs);
	float getXPosition();
	Weapons& getWeapon();
protected:
	sf::Texture playerTexture;
	sf::Texture west;
	sf::Texture east;
	sf::Sprite playerSprite;
	sf::Vector2f Velocity;
	sf::Clock dmgTime;
	sf::Clock releaseTime;
	sf::Clock deathTimer;
	float gravity = 950.f;
	float attackTimer = 0;
	float attackDuration = 0.3f;;
	float iFrames = 0.5f;
	int health;
	int damage = 10;
	int weaponAngle;
	bool inAir;
	bool seeWeapon;
	bool rightSight;
	bool isAttacking;
	bool fallStart = false;
	bool noTerrain;
	Weapons playerWeapon;

};