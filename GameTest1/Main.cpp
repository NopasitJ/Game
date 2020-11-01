#include <SFML/Graphics.hpp>
#include<iostream>
#include "animation.h"
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Game from scratch!");
	//circle
	sf::CircleShape collision(100.f);
	collision.setPosition({ 200.f,200.f });
	collision.setFillColor(sf::Color::Red);
	////texture
	sf::Texture playerTexture;
	if(!playerTexture.loadFromFile("image/charmander.png"))
	{
		cout << "Load failed" << endl;
		return 0;
	}
	//////Sprite
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);
	//shapeSprite.setTextureRect(sf::IntRect(0, 0, 60, 60));

	//////animation
	animation Animation(&playerTexture, sf::Vector2u(9, 6), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		window.draw(shapeSprite);
		window.draw(collision);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(.1f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shapeSprite.move(-.1f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			shapeSprite.move(0.f, -.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			shapeSprite.move(0.f, .1f);
		}
		if (shapeSprite.getGlobalBounds().intersects(collision.getGlobalBounds())) {
			shapeSprite.setPosition(10.f, 10.f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		Animation.Update(0, deltaTime);
		shapeSprite.setTextureRect(Animation.uvRect);
		window.clear();
		//window.draw(playerTexture);
		window.draw(collision);
		//window.display();
	}
	return 0;
}