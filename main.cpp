#include "MainMenu.h"

int main()
{
    RenderWindow window(VideoMode(1900, 900), "Our Game Menu");

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            // I pass all events to menu handler
            menu.handleInput(window, event);
        }

        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;
}