# SFML_GAME
4 - Create new empty C++ console application project.

5 - Open project properties setting (alt+enter shortcut).

6 - For All Configurations, Under Configuration Properties - General : Set C++ Language Standard to ISO C++17 (or anything higher).

7 - For All Configurations, Under Configuration Properties - C/C++-General : Add Additional Include Directory YourPathHere\SFML-3.0.0\include

8 - For All Configurations, Under Configuration Properties-Linker-General : Add Additional Library Directory YourPathHere\SFML-3.0.0\lib

8 - For Debug Configuration, Configuration Properties-Linker-Input : Add Additional Dependencies sfml-window-d.lib sfml-graphics-d.lib sfml-system-d.lib

    Lines for Linker-Input (Debug):
    sfml-graphics-d.lib
    sfml-window-d.lib
    sfml-audio-d.lib
    sfml-network-d.lib
    sfml-system-d.lib

9 - For Release Configuration, Configuration Properties-Linker-Input : Add Additional Dependencies sfml-window.lib sfml-graphics.lib sfml-system.lib

    Lines for Linker-Input (Release):
    sfml-graphics.lib
    sfml-window.lib
    sfml-audio.lib
    sfml-network.lib
    sfml-system.lib



10 - Paste in the following test code from SFML https://www.sfml-dev.org/tutorials/3....

    #include <SFML/Graphics.hpp>
    
    int main()
    {
        sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
    
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
    
            window.clear();
            window.draw(shape);
            window.display();
        }
    }
