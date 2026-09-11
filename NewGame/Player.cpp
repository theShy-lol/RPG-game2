#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Constants.h"

Player::Player(sf::Vector2f v, sf::Texture pT, sf::Sprite pS) {
	this->playerTexture = pT;
	this->playerSprite = pS;
	this->Velocity = v;
	this->playerTexture.setSmooth(false);
	if (!this->playerTexture.loadFromFile("rotations/south.png")) {
		std::cout << "Texture couldn't load" <<std::endl;
	}
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, GROUND_POSITION));
}
void Player::move(float dt) {
	this->Velocity.x = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->Velocity.x = -360.f;
		if (!this->playerTexture.loadFromFile("rotations/west.png")) {
			std::cout << "Texture couldn't load" << std::endl;
		}
		this->playerSprite.setTexture(this->playerTexture);
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->Velocity.x = 360.f;
		if (!this->playerTexture.loadFromFile("rotations/east.png")) {
			std::cout << "Texture couldn't load" << std::endl;
		}
		this->playerSprite.setTexture(this->playerTexture);
	}
	else {
		if (!this->playerTexture.loadFromFile("rotations/south.png")) {
			std::cout << "Texture couldn't load" << std::endl;
		}
		this->playerSprite.setTexture(this->playerTexture);
	}
	if (this->playerSprite.getPosition().x < 0) {
		this->playerSprite.setPosition(0.f,
			this->playerSprite.getPosition().y);
	}
}
void Player::jump() {
	if (this->inAir) {
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->Velocity.y -= 500.f;
		this->inAir = true;
	}
}

void Player::draw(sf::RenderWindow& w) {
	w.draw(this->playerSprite);
}
void Player::update(float dt) {
	this->Velocity.y += this->gravity * dt;
	this->playerSprite.move(this->Velocity.x * dt, this->Velocity.y * dt);
	if (this->playerSprite.getPosition().y > GROUND_POSITION) {
		this->playerSprite.setPosition(this->playerSprite.getPosition().x,
			GROUND_POSITION);
		this->Velocity.y = 0.f;
		this->inAir = false;
	}
}
float Player::getXPosition() {
	return this->playerSprite.getPosition().x;
}