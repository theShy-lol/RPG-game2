#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

class Weapons {
public:
	Weapons();
	void drawWeapon(sf::RenderWindow &w);
	void slide();
private:
	sf::RectangleShape weapon;
	int damage;
};