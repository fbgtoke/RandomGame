#ifndef _SCENE_TEST_INCLUDE
#define _SCENE_TEST_INCLUDE

#include "Scene.hpp"
#include "Tilemap.hpp"
#include "Character.hpp"
#include "CharacterBehavior.hpp"

class SceneTest : public Scene {
public:
  SceneTest();
  ~SceneTest() override;

  void init() override;
  void event(const sf::Event& event) override;
  void update(const sf::Time& deltatime) override;
  void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
  void end() override;

  Tilemap& getTilemap();
  std::list<Character*>& getCharacters();

  void follow(Character* character);

  void loadFromFile(const std::string& filename);

private:
  Tilemap mTilemap;
  std::list<Character*> mCharacters;

  sf::View mView;
  Character* mFollowing;

  bool canMoveTowards(const Character* character, Direction direction) const;
  bool characterAtTile(const sf::Vector2i& tile) const;
};

#endif // _SCENE_TEST_INCLUDE