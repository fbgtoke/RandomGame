#ifndef _ANIMATED_SPRITE_READER_HPP
#define _ANIMATED_SPRITE_READER_HPP

#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "AnimationReader.hpp"

class AnimatedSpriteReader : public GameObject {
public:
  static void read(AnimatedSprite* sprite, const std::string& filename);
  static void read(AnimatedSprite* sprite, const Json& json);

private:
  static const std::string kPrefix;
};

#endif // _ANIMATED_SPRITE_READER_HPP