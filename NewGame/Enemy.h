#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.h"

class Enemy : public Player {
public:
	Enemy(sf::Vector2f v, int h);
	void update(float dt) override;
	void move() override;
	void die();
	void setEnemyPos(float x, float y);
	bool collisionEnemy(Weapons& sword, Player& player);
	sf::Sprite& getEnemy();
	int& enemyDmg();
	float& getVelocity();
private:
	sf::Texture enemyTexture;
	sf::Texture enemyWest;
	sf::Texture enemyEast;
	float speedX = -150.f;
};