#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Weapons.h"

Weapons::Weapons() {
	this->weapon.setSize(sf::Vector2f(70.f, 2.f));
	this->weapon.setFillColor(sf::Color::White);
	this->weapon.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, GROUND_POSITION + 23));
	this->weapon.setOrigin(22.f, 2.f);
	this->weapon.setRotation(90);
	this->damage = 50;
}
void Weapons::drawWeapon(sf::RenderWindow &w) {
	w.draw(this->weapon);
}
bool Weapons::slide() {
	if (!this->weaponDown) {
		this->weapon.setRotation(0);
		this->weaponDown = true;
	}
	return true;
}
void Weapons::recoil() {
	if (this->weaponDown) {
		this->weapon.setRotation(-90);
		this->weaponDown = false;
	}
}
void Weapons::updateWeapon(int posx, int posy) {
	this->weapon.setPosition(posx, posy);
}

sf::FloatRect Weapons::getWeaponBounds() {
	sf::FloatRect weaponBounds = this->weapon.getGlobalBounds();
	return weaponBounds;
}

int& Weapons::getDamage() {
	return this->damage;
}


