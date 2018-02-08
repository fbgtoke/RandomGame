#ifndef _ANIMATED_SPRITE_READER_HPP
#define _ANIMATED_SPRITE_READER_HPP

#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "AnimationReader.hpp"

class AnimatedSpriteReader : public GameObject {
public:
  static void read(AnimatedSprite& sprite, const std::string& filename);
  static void read(AnimatedSprite& sprite, std::ifstream& stream);

private:
  static void readAnimation(AnimatedSprite& sprite, std::ifstream& stream);
  static void readTexture(AnimatedSprite& sprite, const std::string& line);
};

#endif // _ANIMATED_SPRITE_READER_HPP