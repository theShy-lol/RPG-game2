#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

class Obstacle {
public:
	Obstacle();
	void drawObstacle(sf::RenderWindow& w);
private:
	sf::RectangleShape obstacle;
	int nrObstacles = 5;
};