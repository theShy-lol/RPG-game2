#include<iostream>
#include<SFML/Graphics.hpp>
#include"EnemySpawn.h"
#include"Constants.h"

EnemySpawner::EnemySpawner(float x, float y, std::vector<sf::RectangleShape>& obs) {
	int health = 100;
	sf::Vector2f velocity(250.f, 250.f);
	enemies.reserve(numOfEnemies);
	for(int p = 0; p < this->numOfEnemies; ++p){
		this->enemies.emplace_back(velocity, health);
		enemies[p].setEnemyPos(x, y);
		sf::FloatRect enemieBounds = enemies[p].getEnemy().getGlobalBounds();
		for (const auto& ob : obs) {
			sf::FloatRect obsBounds = ob.getGlobalBounds();
			if (enemieBounds.intersects(obsBounds)) {
				if (enemieBounds.top + enemieBounds.height >= obsBounds.top) {
					enemies[p].getEnemy().setPosition(
					enemies[p].getEnemy().getPosition().x,
					obsBounds.top - enemieBounds.height);
				}
			}
		}
		x += ENEMY_DISTANCE_X;
	}
}


void EnemySpawner::drawEnemies(sf::RenderWindow& w) {
	for (auto enemie : this->enemies) {
		w.draw(enemie.getEnemy());
	}
}