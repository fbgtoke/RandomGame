#include "Scene.hpp"
#include "SceneTest.hpp"

Scene::Scene() : mCurrentState(Scene::Uninitialized) {}

Scene::~Scene() {}

void Scene::init() { mCurrentState = Scene::Initialized; }

void Scene::event(const sf::Event& event) {
  getInput().processEvent(event);
}

void Scene::update(const sf::Time& deltatime) {}

void Scene::draw(sf::RenderTarget& window, sf::RenderStates states) const {}

void Scene::end() { mCurrentState = Scene::Ended; }

Scene::State Scene::getState() const { return mCurrentState; }
bool Scene::hasEnded() const { return mCurrentState == Scene::Ended; }

Scene* Scene::create(Scene::Type type) {
  switch (type) {
  case Scene::Test: return new SceneTest(); break;
  default: return nullptr; break;
  }
}