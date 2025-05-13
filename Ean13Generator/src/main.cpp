#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Button.h"
#include "Drawing.h"
#include "Ean13Barcode.h"
#include "Ean13Patterns.h"
#include "Ean13Generator.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ ScreenSize, ScreenSize }), "SFML window");
    sf::Font font("arialmt.ttf");

    vector<int> currentBinaryPattern;
    bool barcodeReady = false;

    TextBox inputBox({ 550, 50 }, font, 16);
    Button barcodeGeneration({ 550, 50 }, font, 16);

    // Настройка объектов inputBox и barCodeGeneration
    setupUI(inputBox, barcodeGeneration);
    
    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (auto* TextEvent = event->getIf<sf::Event::TextEntered>()) {
                inputBox.Typed(*TextEvent);
            }
            if (auto* MouseEvent = event->getIf<sf::Event::MouseMoved>()) {
                barcodeGeneration.isPointed(MouseEvent->position);
                window.display();
            }
            if (auto* MousePressedEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (MousePressedEvent->button == sf::Mouse::Button::Left && barcodeGeneration.getPointed()) {
                    string temp_code = inputBox.getText();

                    if (temp_code.empty()) {
                        cout << "Random Generation" << endl;
                        temp_code = Ean13Generator::generateRandomEan13();
                    }
                    else if (temp_code.length() == 12) {
                        cout << "Barcode Generation" << endl;
                        temp_code = Ean13Generator::generateEan13(temp_code);
                    }
                    else if (temp_code.length() < 12) {
                        cout << "Incorrect input" << endl;
                        barcodeReady = false;
                        continue; 
                    }
                    inputBox.setTextString(temp_code);
                    inputBox.setCountLimit(13);
                    inputBox.setLimit();

                    try {
                        Ean13Barcode barcode(temp_code);
                        currentBinaryPattern = barcode.getBinaryPattern();
                        barcodeReady = true;
                    }
                    catch (const exception& exception) {
                        cerr << "Error: " << exception.what() << endl;
                        barcodeReady = false;
                    }
                }
            }
        }
        // Рендер объектов
        drawUI(window, inputBox, barcodeGeneration, barcodeReady, currentBinaryPattern);
    }
    return 0;
}