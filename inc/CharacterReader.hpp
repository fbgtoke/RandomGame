#ifndef _CHARACTER_READER_HPP
#define _CHARACTER_READER_HPP

#include "GameObject.hpp"
#include "Character.hpp"

class CharacterReader : public GameObject {
public:
  static void read(Character* character, const std::string& filename);
  static void read(Character* character, const Json& json);

private:
  static const std::string kPrefix;
};

#endif // _CHARACTER_READER_HPP