#ifndef _ANIMATION_READER_HPP
#define _ANIMATION_READER_HPP

#include "GameObject.hpp"
#include "Animation.hpp"

class AnimationReader : public GameObject {
public:
  static void read(Animation* animation, const std::string& filename);
  static void read(Animation* animation, std::ifstream& stream);
private:
  static const std::string kPrefix;
  static void readFrame(Animation* animation, const std::string& line);
  static void readTimePerFrame(Animation* animation, const std::string& line);
  static void readRepeat(Animation* animation, const std::string& line);
  static void readPlay(Animation* animation, const std::string& line);
};

#endif // _ANIMATION_READER_HPP