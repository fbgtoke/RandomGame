#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include "GameObject.hpp"
#include "AnimatedSprite.hpp"

class Character : public GameObject {
public:
  Character();
  ~Character() override;

  void init() override;
  void update(const sf::Time& deltatime) override;
  void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
  void end() override;

  void moveTowards(Direction dir);

private:
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
  float mSpeed;
  float mThreshold;
  float mTileSize;
};

#endif // _CHARACTER_HPP