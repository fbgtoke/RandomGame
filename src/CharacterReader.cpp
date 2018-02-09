#include "CharacterReader.hpp"

const std::string CharacterReader::kPrefix = "res/characters/";

void CharacterReader::read(Character& character, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  if (file.is_open()) {
    read(character, file);
    file.close();
  } else {
    std::cout << "Could not load character " << filename << std::endl;
  }
}

void CharacterReader::read(Character& character, std::ifstream& stream) {
  std::string line;

  while (getline(stream, line)) {
    if (line.find("animatedSprite") != std::string::npos) readAnimatedSprite(character, line);
    else if (line.find("texture") != std::string::npos) readTexture(character, line);
    else if (line.find("behavior") != std::string::npos) readBehavior(character, line);
    else if (line.find("tileSize") != std::string::npos) readTileSize(character, line);
    else if (line.find("threshold") != std::string::npos) readThreshold(character, line);
    else if (line.find("walkSpeed") != std::string::npos) readWalkSpeed(character, line);
    else if (line.find("runSpeed") != std::string::npos) readRunSpeed(character, line);
    else if (line.find("position") != std::string::npos) readPosition(character, line);
    else if (line.find("direction") != std::string::npos) readDirection(character, line);
  }
}

void CharacterReader::readAnimatedSprite(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  std::string spriteName;
  
  stream >> command >> spriteName;
  character.getSprite().loadFromFile(spriteName);
}

void CharacterReader::readTexture(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  std::string textureName;
  
  stream >> command >> textureName;

  sf::Texture* texture = getResource().texture(textureName);
  character.getSprite().setTexture(*texture);
}

void CharacterReader::readBehavior(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  unsigned int type;
  
  stream >> command >> type;

  CharacterBehavior::Type behaviorType = static_cast<CharacterBehavior::Type>(type);
  CharacterBehavior* behavior = CharacterBehavior::create(behaviorType, &character);
  character.setBehavior(behavior);
}

void CharacterReader::readTileSize(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  unsigned int tileSize;
  
  stream >> command >> tileSize;
  character.setTileSize(tileSize);
}

void CharacterReader::readThreshold(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  float threshold;
  
  stream >> command >> threshold;
  character.setThreshold(threshold);
}

void CharacterReader::readWalkSpeed(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  float walkSpeed;
  
  stream >> command >> walkSpeed;
  character.setWalkSpeed(walkSpeed);
}

void CharacterReader::readRunSpeed(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  float runSpeed;
  
  stream >> command >> runSpeed;
  character.setRunSpeed(runSpeed);
}

void CharacterReader::readPosition(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  sf::Vector2i position;
  
  stream >> command >> position.x >> position.y;
  character.setPositionInTiles(position);
}

void CharacterReader::readDirection(Character& character, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  unsigned int direction;
  
  stream >> command >> direction;
  character.setDirection(static_cast<Direction>(direction));
}
