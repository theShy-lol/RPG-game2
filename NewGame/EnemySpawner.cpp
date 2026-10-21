#include<iostream>
#include<SFML/Graphics.hpp>
#include"EnemySpawn.h"
#include"Constants.h"

EnemySpawner::EnemySpawner(float x, float y, std::vector<sf::RectangleShape>& obs) {
	for(int p = 0; p < this->numOfEnemies; ++p){
		sf::FloatRect enemieBounds = this->templateBoy.getEnemy().getGlobalBounds();
		for (auto ob : obs) {
			sf::FloatRect obsBounds = ob.getGlobalBounds();
			this->enemies.emplace_back(this->templateBoy);
			this->templateBoy.setEnemyPos(x, y);
			x += ENEMY_DISTANCE_X;
			if (enemieBounds.intersects(obsBounds)) {
				if (this->templateBoy.getEnemy().getPosition().y >= ob.getPosition().y) {
					this->templateBoy.getEnemy().setPosition(
					this->templateBoy.getEnemy().getPosition().x,
					ob.getPosition().y);
				}
			}
		}
	}
}


void EnemySpawner::drawEnemies(sf::RenderWindow& w) {
	for (auto enemie : this->enemies) {
		w.draw(enemie.getEnemy());
	}
}