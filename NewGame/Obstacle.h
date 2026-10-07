#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Player.h"

class Obstacle {
public:
	Obstacle();
	void drawObstacle(sf::RenderWindow& w);
	void straightObstacle(int nr);
	void stairsObstacle(int nr);
	void decreaseObstacle(int nr);
	std::vector<sf::RectangleShape>& getObstacle();
private:
	std::vector<sf::RectangleShape> obstacle;
	float obstacleStartAgain = 300;
};