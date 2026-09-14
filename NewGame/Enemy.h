#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.h"

class Enemy : public Player {
public:
	Enemy(sf::Texture et, sf::Sprite es, sf::Vector2f v);
	void update(float dt) override;
	sf::Sprite& getEnemy();
private:
	float speedX = -150.f;
};