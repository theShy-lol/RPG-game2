#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<vector>

class Enemy : public Player {
public:
	Enemy(sf::Texture et, sf::Sprite es, sf::Vector2f v, int h);
	void update(float dt) override;
	void move() override;
	void die();
	bool collisionEnemy(Weapons& sword, Player& player);
	sf::Sprite& getEnemy();
	int& enemyDmg();
private:
	sf::Texture enemyTexture;
	sf::Texture enemyWest;
	sf::Texture enemyEast;
	float speedX = -150.f;
};