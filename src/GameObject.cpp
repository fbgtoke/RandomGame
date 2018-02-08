#include "GameObject.hpp"

ResourceManager GameObject::mResourceManager = ResourceManager();
Input GameObject::mInput = Input();

void GameObject::init() {}
void GameObject::event(const sf::Event& event) {}
void GameObject::update(const sf::Time& deltatime) {}
void GameObject::draw(sf::RenderTarget& window, sf::RenderStates states) const {}
void GameObject::end() {}

ResourceManager& GameObject::getResource() { return mResourceManager; }
Input& GameObject::getInput() { return mInput; }
