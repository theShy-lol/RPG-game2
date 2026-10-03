#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Constants.h"

Player::Player(sf::Vector2f v, sf::Texture pT, sf::Sprite pS) {
	this->playerTexture = pT;
	this->playerSprite = pS;
	this->Velocity = v;
	this->rightSight = true;
	this->seeWeapon = true;
	this->playerTexture.setSmooth(false);
	this->attackDuration = 0.2f;
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
		this->rightSight = false;
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->Velocity.x = 360.f;
		if (!this->playerTexture.loadFromFile("rotations/east.png")) {
			std::cout << "Texture couldn't load" << std::endl;
		}
		this->playerSprite.setTexture(this->playerTexture);
		this->rightSight = true;
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
	if (this->seeWeapon) {
		this->playerWeapon.drawWeapon(w);
	}
}
void Player::update(float dt) {
	sf::FloatRect playerBounds = this->playerSprite.getGlobalBounds();
	this->attackTimer -= dt;
	this->Velocity.y += this->gravity * dt;
	this->playerSprite.move(this->Velocity.x * dt, this->Velocity.y * dt);
	if (this->rightSight) {
		this->playerWeapon.updateWeapon(this->playerSprite.getPosition().x + 18,
		this->playerSprite.getPosition().y + 23);
		this->weaponAngle = 0;
	}
	else {
		this->playerWeapon.updateWeapon(this->playerSprite.getPosition().x,
			this->playerSprite.getPosition().y + 23);
		this->weaponAngle = 180;
		this->playerWeapon.getWeapon().setOrigin(22 - playerBounds.width, 2.f);
	}
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
bool Player::collision(sf::Sprite& eS) {
	sf::FloatRect playerBound = this->playerSprite.getGlobalBounds();
	sf::FloatRect enemyBounds = eS.getGlobalBounds();
	if (playerBound.intersects(enemyBounds)) {
		if (this->dmgTime.getElapsedTime().asSeconds() >= this->iFrames) {
			this->health -= 10;
			this->dmgTime.restart();
		}
		float playerCentreX = playerBound.left + (playerBound.width / 2);
		float enemyCentreX = enemyBounds.left + (enemyBounds.width / 2);
		float knobackStr = 20.f;
		if (playerCentreX < enemyCentreX) {
			this->playerSprite.move(-knobackStr, -knobackStr / 2.f);
			this->Velocity.x = -5.f;
		}
		else {
			this->playerSprite.move(knobackStr, -knobackStr / 2.f);
			this->Velocity.x = 5.f;
		}
		return true;
	}
	return false;
}
bool Player::attack() {
	if (this->isAttacking) {
		if (this->releaseTime.getElapsedTime().asSeconds() >= this->attackDuration) {
			this->isAttacking = false;
			this->playerWeapon.recoil();
		}
		return this->isAttacking;
	}
	if (this->attackTimer <= 0) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->playerWeapon.slide(this->weaponAngle);
			this->releaseTime.restart();
			this->isAttacking = true;
			this->attackTimer = ATTACK_COOLDOWN;
			return true;
		}
	}
	return false;
}

void Player::getHit(int& dmg) {
	this->health -= dmg;
}
Weapons& Player::getWeapon(){
	return this->playerWeapon;
}


