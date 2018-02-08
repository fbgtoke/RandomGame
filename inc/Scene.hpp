#ifndef _SCENE_HPP
#define _SCENE_HPP

#include "GameObject.hpp"

class Scene : public GameObject {
public:
  Scene();
  virtual ~Scene();

  virtual void init();
  virtual void event(const sf::Event& event);
  virtual void update(const sf::Time& deltatime);
  virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
  virtual void end();

  enum State {
    Uninitialized,
    Initialized,
    Ended
  };
  Scene::State getState() const;
  bool hasEnded() const;

  enum Type {
    Test
  };
  static Scene* create(Scene::Type type);

protected:
  Scene::State mCurrentState;

};

#endif // _SCENE_HPP