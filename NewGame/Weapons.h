#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>


class Weapons {
public:
	Weapons();
	void drawWeapon(sf::RenderWindow &w);
	void updateWeapon(int posx, int posy);
	sf::RectangleShape getWeapon();
	int& getDamage();
	sf::FloatRect getWeaponBounds();
	void recoil();
	bool slide(int angle);
private:
	sf::RectangleShape weapon;
	int damage;
	int weaponSpeed = 25;
	bool weaponDown = false;
};