#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Enemy.h"

Enemy::Enemy(sf::Texture eT, sf::Sprite pS,sf::Vector2f v) : Player(v,eT, pS) {
	this->playerTexture = eT;
	this->playerTexture.setSmooth(false);
	if (!this->playerTexture.loadFromFile("enemy/south.png")) {
		std::cout << "Texture couldn't load" << std::endl;
	}
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 + 200, GROUND_POSITION));
}