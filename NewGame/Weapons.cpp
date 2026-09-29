#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Weapons.h"

Weapons::Weapons() {
	this->weapon.setSize(sf::Vector2f(20.f, 2.f));
	this->weapon.setFillColor(sf::Color::White);
	this->weapon.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, GROUND_POSITION + 13));
	this->weapon.rotate(90);
	this->damage = 50;
}
void Weapons::drawWeapon(sf::RenderWindow &w) {
	w.draw(this->weapon);
}
void Weapons::slide() {
	if (!this->weaponDown) {
		this->weapon.rotate(-90);
		this->weaponDown = true;
	}
	this->weapon.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, GROUND_POSITION + 13));
}