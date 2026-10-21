#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Enemy.h"

class EnemySpawner {
public:
	EnemySpawner(float x, float y, std::vector<sf::RectangleShape>& obs);
	void drawEnemies(sf::RenderWindow& w);
private:
	std::vector<Enemy> enemies;
	Enemy templateBoy;
	int numOfEnemies = 15;
};