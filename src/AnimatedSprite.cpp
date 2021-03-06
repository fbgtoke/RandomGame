#include "AnimatedSprite.hpp"
#include "AnimatedSpriteReader.hpp"

AnimatedSprite::AnimatedSprite() : GameObject(), sf::Sprite() {
  mCurrentAnimation = -1;

  mAnimations = std::vector<Animation*>(0);
}

AnimatedSprite::~AnimatedSprite() {
  for (Animation* animation : mAnimations)
    delete animation;
  mAnimations.clear();
}

void AnimatedSprite::event(const sf::Event& event) {
  GameObject::event(event);
}

void AnimatedSprite::update(const sf::Time& deltatime) {
  GameObject::update(deltatime);

  if (mCurrentAnimation != -1) {
    mAnimations[mCurrentAnimation]->update(deltatime);

    sf::IntRect rect = mAnimations[mCurrentAnimation]->getCurrentFrame();
    setTextureRect(rect);
  }

}

void AnimatedSprite::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  GameObject::draw(window, states);

  sf::Sprite sprite = *this;
  window.draw(sprite);
}

void AnimatedSprite::end() {
  GameObject::end();
}

void AnimatedSprite::setNumberOfAnimations(unsigned int numAnimations) {
  mAnimations.clear();
  mAnimations = std::vector<Animation*> (numAnimations);

  if (numAnimations != 0) {
    mCurrentAnimation = 0;
    
    for (Animation* animation : mAnimations) {
      animation = new Animation();
      animation->init();
    }
  } else {
    mCurrentAnimation = -1;
  }
}

void AnimatedSprite::addAnimation() {
  mAnimations.push_back(new Animation());
  mAnimations[mAnimations.size()-1]->init();

  if (mAnimations.size() == 1) {
    mCurrentAnimation = 0;
  }
}

void AnimatedSprite::changeAnimation(unsigned int index) {
  if (index < mAnimations.size()) {
    mCurrentAnimation = index;
  }
}

Animation* AnimatedSprite::getAnimation(unsigned int index) {
  if (index < mAnimations.size())
    return mAnimations[index];
  return nullptr;
}

Animation* AnimatedSprite::getCurrentAnimation() {
  if (mCurrentAnimation != -1)
    return mAnimations[mCurrentAnimation];
  return nullptr;
}

unsigned int AnimatedSprite::getNumberOfAnimations() const { return mAnimations.size(); }

void AnimatedSprite::loadFromFile(const std::string& filename) {
  AnimatedSpriteReader::read(this, filename);
}