#include<iostream>
#include"Constants.h"
#include"Obstacle.h"





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
	float startX = 1200 + this->obstacleStartAgain;
	float startY = GROUND_POSITION - this->obstacleStartAgain;
	float spaceY = 0.f;
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
	float spaceY = -OBSTACLE_HEIGHT;
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
	float startX = 1200 + (this->obstacleStartAgain * 3);
	float spaceY = OBSTACLE_HEIGHT;
	float startY = GROUND_POSITION - this->obstacleStartAgain;
	for (int i = 0; i < nr; ++i) {
		sf::RectangleShape moron;
		moron.setPosition(sf::Vector2f(startX + (i * spaceX),
			startY + (i * spaceY)));
		moron.setSize(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
		moron.setFillColor(sf::Color::Red);
		this->obstacle.push_back(moron);
	}
}
