#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>

int main(int argc, char **argv) {

    sf::Window window(sf::VideoMode({600, 480}), "Hello World");

    const auto onClose = [&window](const sf::Event::Closed &) {
        window.close();
    };

    const auto onKeyPress =
        [&window](const sf::Event::KeyPressed &key_pressed) {
            if (key_pressed.code == sf::Keyboard::Key::Q) {
                window.close();
            }
        };

    while (window.isOpen()) {
        window.handleEvents(onClose, onKeyPress);
        window.clear(sf::Color::Black);
    }

    return 0;
}
