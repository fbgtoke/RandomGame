#ifndef _ANIMATION_READER_HPP
#define _ANIMATION_READER_HPP

#include "GameObject.hpp"
#include "Animation.hpp"

class AnimationReader : public GameObject {
public:
  static void read(Animation* animation, const std::string& filename);
  static void read(Animation* animation, Json& json);
private:
  static const std::string kPrefix;
};

#endif // _ANIMATION_READER_HPP