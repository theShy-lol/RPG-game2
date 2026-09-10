#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Terrain.h"
#include"Constants.h"

Terrain::Terrain(int n) {
	this->nr = n;
	this->terrain.setSize(sf::Vector2f(150.f, 70.f));
	this->terrain.setFillColor(sf::Color::Blue);
}
void Terrain::drawTerrain(sf::RenderWindow &w) {
	float space = 50.f;
	float startx = 0.f; 
	for (int i = 0; i < this->nr; i++) {
		this->terrain.setPosition(sf::Vector2f(startx + (i * space), GROUND_POSITION + 50.f));
		w.draw(this->terrain);
	}
}