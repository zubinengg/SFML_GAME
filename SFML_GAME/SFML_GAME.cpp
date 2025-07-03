// SFML_GAME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Lines for Linker-Input (Release):
sfml-graphics.lib
sfml-window.lib
sfml-audio.lib
sfml-network.lib
sfml-system.lib

Lines for Linker-Input (Debug):
sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-network-d.lib
sfml-system-d.lib
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>

static std::string string_iteratiror(std::string s)
{
    std::string result;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        if (it + 1 != s.end())
        {
            result += *it;
            result += ",";
        }
        else
        {
            result += *it;
        }
    }
    return result;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 300 }), "MY SFML Games", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Blue);
    circle.setOrigin({ -100.f, -100.f }); // Set position using sf::Vector2f
    //circle.setOrigin({ circle.getRadius(), circle.getRadius() });
 
	std::string s("device");
	std::cout << string_iteratiror(s) << std::endl;

    while (window.isOpen())    {
        
        
        while (const std::optional ev =window.pollEvent())
        {           
            if (ev->is<sf::Event::Closed>() || ((ev->is<sf::Event::KeyPressed>() && ev->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)))
				window.close();
        }

        window.clear(sf::Color::Cyan);
        // UPdate
        window.draw(circle);

		// Draw
        window.display();
    }
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


