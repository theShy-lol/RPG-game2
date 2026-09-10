#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>

class Terrain {
public:
	Terrain(int n);
	void drawTerrain(sf::RenderWindow &w);
private:
	int nr;
	sf::RectangleShape terrain;
	std::vector<sf::RectangleShape> floor;
};