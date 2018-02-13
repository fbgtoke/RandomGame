#include "SceneReader.hpp"
#include "TilemapReader.hpp"
#include "CharacterReader.hpp"

const std::string SceneReader::kPrefix = "res/maps/";

void SceneReader::read(SceneTest* scene, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  std::string content;
  std::stringstream ss;
  Json json;

  if (file.is_open()) {
    content.assign( (std::istreambuf_iterator<char>(file) ),
                    (std::istreambuf_iterator<char>()    ) );
    
    ss << content;
    ss >> json;
    read(scene, json);

    file.close();
  } else {
    std::cout << "Could not load scene " << filename << std::endl;
  }
}

void SceneReader::read(SceneTest* scene, const Json& json) {
  if (json.count("tilemap") != 0) {
    Json child = json.at("tilemap");
    TilemapReader::read(scene->getTilemap(), child);
  }

  if (json.count("characters") != 0) {
    std::list<Character*>& characters = scene->getCharacters();
    std::vector<Json> children = json.at("characters");

    for (Character* character : characters)
      delete character;
    characters.clear();

    for (unsigned int i = 0; i < children.size(); ++i) {

      Character* character = new Character();
      character->init();
      Json child = children[i];

      CharacterReader::read(character, child);
      characters.push_back(character);
    }
  }
}