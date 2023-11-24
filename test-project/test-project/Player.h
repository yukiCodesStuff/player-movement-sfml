#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture pTexture;
	sf::Sprite curr_sprite;
	float moveSpeed = 0.065f;
	float animationTime = 0.0f;  // Time counter for animation
	float animationUpdateTime = 0.2f;  // Time threshold to update animation
	int animationIndex = 1;
	int animationArrDown[4] = { 130, 180, 230, 180 };
	sf::Clock clock;

public:

	Player(std::string imgPath) {
		if (!pTexture.loadFromFile(imgPath)) {
			perror("Failed to load");
		}

		sf::IntRect rectSourceSprite(animationArrDown[animationIndex], 0, 32, 40);
		curr_sprite.setTexture(pTexture);
		curr_sprite.setTextureRect(rectSourceSprite);
	};

	~Player() {};

	void drawPlayer(sf::RenderWindow &window) {
		window.draw(curr_sprite);
	}

	void notMoving() {
		sf::IntRect rectSourceSpriteStatic(180, 0, 32, 40);
		curr_sprite.setTextureRect(rectSourceSpriteStatic);
	}

	void up() {
		sf::IntRect rectSourceSpriteUp(animationArrDown[animationIndex], 150, 32, 40);
		incrementAnimationIndex();
		curr_sprite.setTextureRect(rectSourceSpriteUp);
		this->curr_sprite.move(0, -moveSpeed);
	};

	void down() {
		sf::IntRect rectSourceSpriteDown(animationArrDown[animationIndex], 0, 32, 40);
		incrementAnimationIndex();
		curr_sprite.setTextureRect(rectSourceSpriteDown);
		this->curr_sprite.move(0, moveSpeed);
	};

	void left() {
		sf::IntRect rectSourceSpriteLeft(animationArrDown[animationIndex], 50, 32, 40);
		incrementAnimationIndex();
		curr_sprite.setTextureRect(rectSourceSpriteLeft);
		this->curr_sprite.move(-moveSpeed, 0);
	};

	void right() {
		sf::IntRect rectSourceSpriteRight(animationArrDown[animationIndex], 100, 32, 40);
		incrementAnimationIndex();
		curr_sprite.setTextureRect(rectSourceSpriteRight);
		this->curr_sprite.move(moveSpeed, 0);
	};

	void incrementAnimationIndex() {
		animationTime += clock.restart().asSeconds();
		if (animationTime >= animationUpdateTime) {
			animationTime = 0;  // Reset the timer
			if (this->animationIndex >= 3) this->animationIndex = 0;
			else this->animationIndex++;
		}
	}

	void setSpeed(float newSpeed) {
		this->moveSpeed = newSpeed;
	};

	sf::Sprite getSprite() {
		return this->curr_sprite;
	};
};