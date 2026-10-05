#include<iostream>
#include"Constants.h"
#include"Obstacle.h"
#include<random>


int getRandomNr() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> randomDist(50, 120);
	return randomDist(gen);
}

Obstacle::Obstacle() {
	for (auto obstacl : obstacle) {
		obstacl.setSize(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
		obstacl.setFillColor(sf::Color::Red);
	}
	

}
void Obstacle::drawObstacle(sf::RenderWindow &w) {
	for (auto& obstacle : this->obstacle) {
		w.draw(obstacle);
	}
}

std::vector<sf::RectangleShape>& Obstacle::getObstacle() {
	return obstacle;
}

void Obstacle::straightObstacle(int nr) {
	float spaceX = OBSTACLE_WIDTH;
	float startX = 1500;
	float startY = GROUND_POSITION - 300;
	int spaceY = 0.f;
	for (int i = 0; i < nr; ++i) {
		sf::RectangleShape straightStairs;
		straightStairs.setPosition(sf::Vector2f(startX + (i * spaceX),
			startY + (i * spaceY)));
		straightStairs.setSize(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
		straightStairs.setFillColor(sf::Color::Red);
		this->obstacle.push_back(straightStairs);
	}

}
void Obstacle::stairsObstacle(int nr) {
	float spaceX = OBSTACLE_WIDTH;
	float startX = 1200;
	int spaceY = -OBSTACLE_HEIGHT;
	float startY = GROUND_POSITION;
	for (int i = 0; i < nr; ++i) {
		sf::RectangleShape moron;
		moron.setPosition(sf::Vector2f(startX + (i * spaceX),
			startY + (i * spaceY)));
		moron.setSize(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
		moron.setFillColor(sf::Color::Red);
		this->obstacle.push_back(moron);
	}
}
void Obstacle::decreaseObstacle(int nr) {
	float spaceX = OBSTACLE_WIDTH;
	float startX = 1200;
	int spaceY = OBSTACLE_HEIGHT;
	float startY = GROUND_POSITION;
	for (int i = 0; i < nr; ++i) {
		sf::RectangleShape moron;
		moron.setPosition(sf::Vector2f(startX + (i * spaceX),
			startY + (i * spaceY)));
		moron.setSize(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
		moron.setFillColor(sf::Color::Red);
		this->obstacle.push_back(moron);
	}
}