#include<iostream>
#include<SFML/Graphics.hpp>
#include"EnemySpawn.h"
#include"Constants.h"

EnemySpawner::EnemySpawner(float x, float y) {
	int health = 100;
	sf::Vector2f velocity(250.f, 250.f);
	sf::FloatRect overlap;
	enemies.reserve(numOfEnemies);
	for(int p = 0; p < this->numOfEnemies; ++p){
		this->enemies.emplace_back(velocity, health);
		enemies[p].setEnemyPos(x, y);
		x += ENEMY_DISTANCE_X;
	}
}


void EnemySpawner::drawEnemies(sf::RenderWindow& w) {
	for (auto enemie : this->enemies) {
		w.draw(enemie.getEnemy());
	}
}


void EnemySpawner::SpawnUpdate(float dt, Player& player, Weapons& weapon, std::vector<sf::RectangleShape>& obs) {
	sf::FloatRect overlap;
	for (int p = 0; p < this->numOfEnemies; ++p) {
		this->enemies[p].die();
		this->enemies[p].move();
		this->enemies[p].update(dt);
		sf::FloatRect enemieBounds = enemies[p].getEnemy().getGlobalBounds();
		if (player.collision(this->enemies[p].getEnemy()) == true) {
			player.getHit(this->enemies[p].enemyDmg());
		}
		if (enemies[p].collisionEnemy(player.getWeapon(), 
			player) == true) {
			this->enemies[p].getHit(weapon.getDamage());
		}
		for (const auto& ob : obs) {
			sf::FloatRect obsBounds = ob.getGlobalBounds();
			float offset = enemieBounds.width;
			float offsetY = enemieBounds.height;
			float bottomY = enemieBounds.top + enemieBounds.height;
			float bootomObs = obsBounds.top + obsBounds.height;
			float rightSide = obsBounds.left + obsBounds.width;
			if (enemieBounds.intersects(obsBounds, overlap)) {
				if (overlap.height > overlap.width) {
					if (enemieBounds.left < obsBounds.left) {
						if (enemies[p].getVelocity() > 0) {
							enemies[p].getEnemy().setPosition(obsBounds.left - offset,
								enemies[p].getEnemy().getPosition().y);
							enemies[p].getVelocity() = -enemies[p].getVelocity();
						}
					}
					else if (enemieBounds.left > obsBounds.left) {
						if (enemies[p].getVelocity() < 0) {
							enemies[p].getEnemy().setPosition(rightSide,
								enemies[p].getEnemy().getPosition().y);
							enemies[p].getVelocity() = -enemies[p].getVelocity();
						}
					}
				}
				else if (overlap.width > overlap.height) {
					if (enemieBounds.top < obsBounds.top) {
						enemies[p].getEnemy().setPosition(enemies[p].getEnemy().getPosition().x,
							obsBounds.top - offsetY);
					}
				}
				else {
						enemies[p].getEnemy().setPosition(enemies[p].getEnemy().getPosition().x,
						bootomObs);
				}
			}
		}
	}
}
