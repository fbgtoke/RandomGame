#ifndef _CHARACTER_READER_HPP
#define _CHARACTER_READER_HPP

#include "GameObject.hpp"
#include "Character.hpp"

class CharacterReader : public GameObject {
public:
  static void read(Character& character, const std::string& filename);
  static void read(Character& character, std::ifstream& stream);

private:
  static const std::string kPrefix;
  static void readAnimatedSprite(Character& character, const std::string& line);
  static void readTexture(Character& character, const std::string& line);
  static void readBehavior(Character& character, const std::string& line);
  static void readTileSize(Character& character, const std::string& line);
  static void readThreshold(Character& character, const std::string& line);
  static void readWalkSpeed(Character& character, const std::string& line);
  static void readRunSpeed(Character& character, const std::string& line);
  static void readPosition(Character& character, const std::string& line);
  static void readDirection(Character& character, const std::string& line);
};

#endif // _CHARACTER_READER_HPP