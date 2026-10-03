#include<iostream>
#include"Constants.h"
#include"Obstacle.h"
#include<random>


int getRandomNr() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> randomDist(50, 70);
	return randomDist(gen);
}

Obstacle::Obstacle() {
	this->obstacle.setSize(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
	this->obstacle.setFillColor(sf::Color::Red);

}
void Obstacle::drawObstacle(sf::RenderWindow &w) {
	for (int i = 0; i < this->nrObstacles; ++i) {
		this->obstacle.setPosition(sf::Vector2f(getRandomNr(), GROUND_POSITION - 300));
		w.draw(this->obstacle);
	}
}
