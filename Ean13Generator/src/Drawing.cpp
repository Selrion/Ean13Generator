#include "Drawing.h"


void barcodeDrawing(const vector<int>& binary_barcode, sf::RenderWindow& window) {
	sf::RectangleShape line({ width_line, height_line });
	line.setPosition({ ScreenSize / 2 - 47 * width_line, ScreenSize / 4 - height_line / 2});
	for (int bit : binary_barcode) {
		if (bit == 1) {
			line.setFillColor(sf::Color::Black);
		}
		else {
			line.setFillColor(sf::Color::White);
		}
		window.draw(line);
		line.setPosition({ line.getPosition().x + width_line, line.getPosition().y });
	}

}


void drawUI(sf::RenderWindow& window,
    TextBox& inputBox,
    Button& barcodeGeneration,
    bool barcodeReady,
    const vector<int>& currentBinaryPattern) {

    window.clear(sf::Color({ 220, 220, 220, 225 }));

    window.draw(inputBox.getRectObject());
    window.draw(inputBox.getTextObject());

    barcodeGeneration.draw(window);

    if (barcodeReady) {
        barcodeDrawing(currentBinaryPattern, window);
    }

    window.display();
}


void setupUI(TextBox& inputBox, Button& barcodeGeneration) {

    inputBox.setRectFillColor(sf::Color({ 210, 210, 210, 225 }));
    inputBox.setRectOutColor(sf::Color::Black);
    inputBox.setRectThickness(2);
    inputBox.setTextColor(sf::Color::Black);
    inputBox.centerPosition({ 300, 400 });

    barcodeGeneration.setRectFillColor(sf::Color({ 210, 210, 210, 225 }));
    barcodeGeneration.setRectOutColor(sf::Color::Black);
    barcodeGeneration.setRectThickness(2);
    barcodeGeneration.setTextString("Generation Barcode");
    barcodeGeneration.setTextColor(sf::Color::Black);
    barcodeGeneration.centerPosition({ 300, 460 });
}
