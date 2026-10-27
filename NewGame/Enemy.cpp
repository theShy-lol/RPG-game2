#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Enemy.h"


Enemy::Enemy(sf::Vector2f v, int h) : Player(v,h) {
	this->health = h;
	this->seeWeapon = false;
	this->enemyTexture.setSmooth(false);
	if (!this->enemyTexture.loadFromFile("enemy/south.png")) {
		std::cout << "Texture couldn't load" << std::endl;
	}
	if(!this->enemyWest.loadFromFile("enemy/west.png")) {
		std::cout << "Texture couldn't load" << std::endl;
	}
	if(!this->enemyEast.loadFromFile("enemy/east.png")) {
		std::cout << "Texture couldn't load" << std::endl;
	}
	this->playerSprite.scale(1.3f, 1.3f);
	this->playerSprite.setTexture(this->enemyTexture);

}

void Enemy::move() {
	if (this->playerSprite.getPosition().x < 50.f) {
		this->Velocity.x = 260;
		this->playerSprite.setTexture(this->enemyEast);
	}
	else if (this->playerSprite.getPosition().x > SCREEN_WIDTH * 4) {
		this->Velocity.x = -260;
		this->playerSprite.setTexture(this->enemyWest);
	}
}

void Enemy::update(float dt) {
	this->Velocity.y += this->gravity * dt;
	this->playerSprite.move(this->Velocity.x * dt, this->Velocity.y * dt);
	if (this->playerSprite.getPosition().y > GROUND_POSITION) {
		this->playerSprite.setPosition(this->playerSprite.getPosition().x,
			GROUND_POSITION);
		this->Velocity.y = 0.f;
	}
}

sf::Sprite& Enemy::getEnemy() {
	return this->playerSprite;
}
void Enemy::die() {
	if (this->health <= 0) {
		this->playerSprite.scale(sf::Vector2f(0.f, 0.f));
	}
}
int& Enemy::enemyDmg()  {
	return this->damage;
}

bool Enemy::collisionEnemy(Weapons& sword, Player& player) {
	float KnockBackStr = 10.f;
	sf::FloatRect swordBounds = sword.getWeaponBounds();
	sf::FloatRect enemyBound = this->playerSprite.getGlobalBounds();
	if (enemyBound.intersects(swordBounds) && player.attack() == true) {
		float enemyCentreX = enemyBound.left + (enemyBound.width / 2);
		float swordCentreX = swordBounds.left + (enemyBound.width / 2);
		if (enemyCentreX < swordCentreX) {
			this->playerSprite.move(KnockBackStr, -KnockBackStr / 2);
			this->Velocity.x = -5.f;
		}
		else {
			this->playerSprite.move(-KnockBackStr, -KnockBackStr / 2);
			this->Velocity.x = 5.f;
		}
		return true;
	}
	return false;
}

void Enemy::setEnemyPos(float x, float y) {
	this->playerSprite.setPosition(x, y);
}
float& Enemy::getVelocity() {
	return Velocity.x;
}
