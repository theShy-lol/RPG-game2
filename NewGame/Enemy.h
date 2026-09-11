#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Constants.h"
#include"Player.h"

class Enemy : public Player {
public:
	Enemy(sf::Texture et, sf::Sprite es, sf::Vector2f v);
};