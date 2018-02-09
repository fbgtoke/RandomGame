#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "CharacterBehavior.hpp"

class Character : public GameObject {
public:
  Character();
  ~Character() override;

  void init() override;
  void update(const sf::Time& deltatime) override;
  void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

  void setBehavior(CharacterBehavior* behavior);

  void moveTowards(Direction dir);

  void setTileSize(unsigned int tileSize);
  void setThreshold(float threshold);
  void setWalkSpeed(float walkSpeed);
  void setRunSpeed(float runSpeed);
  void setDirection(Direction direction);
  void setNextDirection(Direction dir);

  Direction getNextDirection() const;
  AnimatedSprite& getSprite();

  void setRunning(bool run);

  void setPositionInTiles(const sf::Vector2i& position);
  sf::Vector2i getPositionInTiles() const;

  bool isIdle() const;

  void loadFromFile(const std::string& filename);

private:
  CharacterBehavior* mBehavior;

  enum State {
    Idle,
    Walking
  };

  AnimatedSprite mSprite;
  State mState;
  Direction mDirection;

  bool mRunning;

  Direction mNextDirection;
  sf::Vector2f mTargetPosition;
  float mWalkSpeed;
  float mRunSpeed;
  float mThreshold;
  float mTileSize;
};

#endif // _CHARACTER_HPP