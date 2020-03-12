#include "Window.h"

Engine::Window::Window(int width, int height, sf::String title, bool resizable) {
    if (!resizable)
	    window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close);
    else
        window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    
    window->setActive(false);
}

Engine::Window::~Window() {
    delete scene;
	delete window;
}

void Engine::Window::setView(sf::View view) {
    window->setView(view);
}

void Engine::Window::setGameScene(Engine::GameScene* scene) {
    delete this->scene;

    this->scene = scene;
}

void Engine::Window::setVisible(bool visible) {
	this->visible = visible;
}

bool Engine::Window::getVisible() {
	return visible;
}

void Engine::Window::launch() {
    th = std::thread(&Engine::Window::draw, this);
    lifeCycle();
    th.join();
}

void Engine::Window::lifeCycle()
{
    while (window->isOpen()) {
        sf::Event event;
        sf::sleep(sf::milliseconds(SYSTEM_DELAY));

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                window->setActive(false);
            }
        }
    }
}

void Engine::Window::draw()
{
    window->setActive(true);
   
    while (window->isOpen()) {
        sf::sleep(sf::milliseconds(SYSTEM_DELAY));
        scene->run(SYSTEM_DELAY);
        window->clear();

        if (scene != NULL)
            scene->draw(window);

        window->display();
    }
}