#ifndef _SCENE_TEST_INCLUDE
#define _SCENE_TEST_INCLUDE

#include "Scene.hpp"
#include "Tilemap.hpp"
#include "Character.hpp"

class SceneTest : public Scene {
public:
  SceneTest();
  ~SceneTest() override;

  void init() override;
  void event(const sf::Event& event) override;
  void update(const sf::Time& deltatime) override;
  void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
  void end() override;

private:
  Tilemap mTilemap;
  Character mCharacter;
};

#endif // _SCENE_TEST_INCLUDE