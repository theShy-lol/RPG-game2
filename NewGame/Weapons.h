#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

class Weapons {
public:
	Weapons();
	void drawWeapon(sf::RenderWindow &w);
	void updateWeapon(int posx, int posy);
	void recoil();
	void slide();
private:
	sf::RectangleShape weapon;
	int damage;
	int weaponSpeed = 25;
	bool weaponDown = false;
	
};