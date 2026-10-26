#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Enemy.h"
#include"Weapons.h"

class EnemySpawner {
public:
	EnemySpawner(float x, float y);
	void drawEnemies(sf::RenderWindow& w);
	void SpawnUpdate(float dt, Player& player, Weapons& weapon, std::vector<sf::RectangleShape>& obs, bool gap);
private:
	std::vector<Enemy> enemies;
	int numOfEnemies = 6;
};