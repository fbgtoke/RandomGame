#include "CharacterReader.hpp"
#include "AnimatedSpriteReader.hpp"

const std::string CharacterReader::kPrefix = "res/characters/";

void CharacterReader::read(Character& character, const std::string& filename) {
  std::ifstream file(kPrefix + filename);
  
  std::string content;
  std::stringstream ss;
  Json json;

  if (file.is_open()) {
    content.assign( (std::istreambuf_iterator<char>(file) ),
                    (std::istreambuf_iterator<char>()    ) );
    
    ss << content;
    ss >> json;
    read(character, json);

    file.close();
  } else {
    std::cout << "Could not load character " << filename << std::endl;
  }
}

void CharacterReader::read(Character& character, const Json& json) {
  if (json.count("sprite") != 0) {
    Json child = json.at("sprite");
    AnimatedSpriteReader::read(&character.getSprite(), child);
  }

  if (json.count("behavior") != 0) {
    unsigned int type = json.at("behavior");
    CharacterBehavior::Type behaviorType = static_cast<CharacterBehavior::Type>(type);
    CharacterBehavior* behavior = CharacterBehavior::create(behaviorType, &character);
    character.setBehavior(behavior);
  }

  if (json.count("tileSize") != 0) {
    unsigned int tileSize = json.at("tileSize");
    character.setTileSize(tileSize);
  }

  if (json.count("threshold") != 0) {
    float threshold = json.at("threshold");
    character.setThreshold(threshold);
  }

  if (json.count("walkSpeed") != 0) {
    float walkSpeed = json.at("walkSpeed");
    character.setWalkSpeed(walkSpeed);
  }

  if (json.count("runSpeed") != 0) {
    float runSpeed = json.at("runSpeed");
    character.setRunSpeed(runSpeed);
  }

  if (json.count("position") != 0) {
    sf::Vector2i position = {json.at("position")[0], json.at("position")[1]};
    character.setPositionInTiles(position);
  }

  if (json.count("direction") != 0) {
    unsigned int direction = json.at("direction");
    character.setDirection(static_cast<Direction>(direction));
  }
}