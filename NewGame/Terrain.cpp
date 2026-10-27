#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Terrain.h"
#include"Constants.h"

Terrain::Terrain(int n) {
	this->nr = n;
	float space = 50.f;
	float startx = 0.f;
	float gap = 50.f;
	this->allTerrain.reserve(n);
	for (int i = 0; i < n; ++i) {
		if (startx + (i * space) >= 700 && startx + (i * space) <= 850) {
			continue;
		}
		if (startx + (i * space) >= 1100 && startx + (i * space) <= 1200) {
			continue;
		}
		if (startx + (i * space) >= 1300 && startx + (i * space) <= 1400) {
			continue;
		}
		if (startx + (i * space) >= 1600 && startx + (i * space) <= 1800) {
			continue;
		}
		this->allTerrain.emplace_back(sf::Vector2f(150.f, 70.f));
		this->allTerrain.back().setPosition(sf::Vector2f(startx + (i * space), GROUND_POSITION + 50.f));
		this->allTerrain.back().setFillColor(sf::Color::Blue);
	}
	
}
void Terrain::drawTerrain(sf::RenderWindow &w) {
	for (const auto& terrain: this->allTerrain) {
		w.draw(terrain);
	}
}

