#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include "Utils.hpp"
#include "ResourceManager.hpp"
#include "Input.hpp"

class GameObject : public sf::Drawable {
public:
  GameObject() {};
  virtual ~GameObject() {};

  virtual void init();
  virtual void event(const sf::Event& event);
  virtual void update(const sf::Time& deltatime);
  virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
  virtual void end();

  static ResourceManager& getResource();
  static Input& getInput();

private:
  static ResourceManager mResourceManager;
  static Input mInput;
};

#endif // _GAME_OBJECT_HPP