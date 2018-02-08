#ifndef _ANIMATED_SPRITE_HPP
#define _ANIMATED_SPRITE_HPP

#include "GameObject.hpp"
#include "Animation.hpp"

class AnimatedSprite : public GameObject, public sf::Sprite {
public:
  AnimatedSprite();
  ~AnimatedSprite() override;

  void init() override;
  void event(const sf::Event& event) override;
  void update(const sf::Time& deltatime) override;
  void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
  void end() override;

  void setNumberOfAnimations(unsigned int numAnimations);
  void addAnimation();
  void changeAnimation(unsigned int index);
  Animation& getAnimation(unsigned int index);
  Animation& getCurrentAnimation();

  unsigned int getNumberOfAnimations() const;

  void loadFromFile(const std::string& filename);

private:
  int mCurrentAnimation;
  std::vector<Animation> mAnimations;
};

#endif // _ANIMATED_SPRITE_HPP