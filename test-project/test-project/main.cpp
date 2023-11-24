#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Player.h"

void main(int argc, char** argv[]) {

	sf::RenderWindow renderWindow(sf::VideoMode(720, 720), "Pokemon Mock");
	sf::Event event;

	Player player("tr-sprite.png");
	sf::Clock clock;

	sf::Texture test_texture;
	test_texture.loadFromFile("tr-sprite.png");

	int animationArrDown[4] = { 130, 180, 230, 180 };
	int animationIndex = 1;

	sf::IntRect rectSourceSpriteUp(animationArrDown[animationIndex], 150, 32, 40);
	sf::IntRect rectSourceSpriteDown(animationArrDown[animationIndex], 0, 32, 40);
	sf::IntRect rectSourceSpriteLeft(animationArrDown[animationIndex], 50, 32, 40);
	sf::IntRect rectSourceSpriteRight(animationArrDown[animationIndex], 100, 32, 40);

	sf::Sprite test_up(test_texture, rectSourceSpriteUp);

	sf::Sprite test_down(test_texture, rectSourceSpriteDown);
	test_down.setPosition(0.0f, 40.0f);

	sf::Sprite test_left(test_texture, rectSourceSpriteLeft);
	test_left.setPosition(0.0f,80.0f);

	sf::Sprite test_right(test_texture, rectSourceSpriteRight);
	test_right.setPosition(0.0f, 120.0f);


	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.down();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.up();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.left();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.right();
		}
		else if (
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
			!sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
			!sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			) {
			player.notMoving();
		}

		renderWindow.clear();
		player.drawPlayer(renderWindow);

		// renderWindow.draw(test_up);
		// renderWindow.draw(test_down);
		// renderWindow.draw(test_left);
		// renderWindow.draw(test_right);

		renderWindow.display();
	}

}