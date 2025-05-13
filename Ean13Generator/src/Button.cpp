#include "Button.h"

using namespace std;

Button::Button(sf::Vector2f rect_size, sf::Font& font, unsigned int size) : rectangle(rect_size), text(font, "", size) {

};

void Button::setTextFont(sf::Font& font) {
	text.setFont(font);
}
void Button::setTextSize(unsigned int size) {
	text.setCharacterSize(size);
}
void Button::setTextColor(sf::Color color) {
	text.setFillColor(color);
}
void Button::setTextString(const string& txt) {
	text.setString(txt);
}
void Button::setTextPos(sf::Vector2f pos) {
	text.setPosition(pos);
}

void Button::setRectPos(sf::Vector2f pos) {
	rectangle.setPosition(pos);
}
void Button::setRectOutColor(sf::Color color) {
	rectangle.setOutlineColor(color);
}
void Button::setRectFillColor(sf::Color color) {
	rectangle.setFillColor(color);
}
void Button::setRectThickness(int size) {
	rectangle.setOutlineThickness(size);
}

float Button::getRectPosX() {
	return rectangle.getPosition().x;
}
float Button::getRectPosY() {
	return rectangle.getPosition().y;
}

float Button::getRectSizeX() {
	return rectangle.getSize().x;
}
float Button::getRectSizeY() {
	return rectangle.getSize().y;
}

sf::Text& Button::getTextObject() {
	return text;
}
sf::RectangleShape& Button::getRectObject() {
	return rectangle;
}

bool Button::getPointed() {
	return statusPointed;
}
void Button::isPointed(sf::Vector2i coords) {
	int temp_mouse_x = coords.x;
	int temp_mouse_y = coords.y;

	if (((temp_mouse_x > rectangle.getGlobalBounds().position.x) && (temp_mouse_x < rectangle.getGlobalBounds().position.x + rectangle.getSize().x)) &&
		((temp_mouse_y > rectangle.getGlobalBounds().position.y) && (temp_mouse_y < rectangle.getGlobalBounds().position.y + rectangle.getSize().y)))
	{
		rectangle.setFillColor(colorPointed);
		statusPointed = true;
	}
	else
	{
		rectangle.setFillColor(colorNotPointed);
		statusPointed = false;
	}
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
	window.draw(text);
}

void Button::centerPosition(sf::Vector2f position) {
	rectangle.setOrigin(rectangle.getSize() / 2.f);
	rectangle.setPosition(position);
	text.setPosition({ position.x - rectangle.getSize().x / 8, position.y - rectangle.getSize().y / 4 });
}




