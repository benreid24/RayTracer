#include <SFML/Graphics.hpp>
#include <iostream>

#include <Line.hpp>

int main() {
    sf::RenderWindow window(
        sf::VideoMode(1920, 1080, 32), "RayTracer", sf::Style::Close | sf::Style::Titlebar);

    Line line({5, 5}, {1, 1});
    std::cout << line.m << " " << line.b << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        window.clear(sf::Color::Blue);
        window.display();
        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}