#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Enemy.h"


Enemy::Enemy(sf::Texture eT, sf::Sprite pS, sf::Vector2f v) : Player(v,eT, pS) {
	this->playerTexture = eT;
	this->playerTexture.setSmooth(false);
	if (!this->playerTexture.loadFromFile("enemy/south.png")) {
		std::cout << "Texture couldn't load" << std::endl;
	}
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.scale(sf::Vector2f(1.5f, 1.5f));
	this->playerSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 + 200, GROUND_POSITION));

}


void Enemy::update(float dt) {
	this->playerSprite.move(this->speedX * dt, 0.0f);
	this->playerSprite.setTexture(this->playerTexture);
	if (this->playerSprite.getPosition().x < 0) {
		this->speedX = std::abs(this->speedX);
		this->playerSprite.setPosition(0.f, this->playerSprite.getPosition().y);
		if (!this->playerTexture.loadFromFile("enemy/east.png")) {
			std::cout << "Texture couldn't load" << std::endl;
		}
		this->playerSprite.setTexture(this->playerTexture);
	}
	if (this->playerSprite.getPosition().x > SCREEN_WIDTH) {
		this->speedX = -std::abs(this->speedX);
		this->playerSprite.setPosition(SCREEN_WIDTH, this->playerSprite.getPosition().y);
		if (!this->playerTexture.loadFromFile("enemy/west.png")) {
			std::cout << "Texture couldn't load" << std::endl;
		}
		this->playerSprite.setTexture(this->playerTexture);
	}
}
sf::Sprite& Enemy::getEnemy() {
	return this->playerSprite;
}

