#include "TilemapReader.hpp"
#include "TilesheetReader.hpp"
const std::string TilemapReader::kPrefix = "res/tilemaps/";

void TilemapReader::read(Tilemap& tilemap, const std::string& filename) {
  std::ifstream file(kPrefix + filename);
  
  std::string content;
  std::stringstream ss;
  Json json;

  if (file.is_open()) {
    content.assign( (std::istreambuf_iterator<char>(file) ),
                    (std::istreambuf_iterator<char>()    ) );
    
    ss << content;
    ss >> json;
    read(tilemap, json);
    
    file.close();
  } else {
    std::cout << "Could not load tilemap " << filename << std::endl;
  }
}

void TilemapReader::read(Tilemap& tilemap, const Json& json) {
  if (json.count("tilesheet") != 0) {
    Json child = json.at("tilesheet");
    TilesheetReader::read(tilemap.getTilesheet(), child);
  }

  if (json.count("size") != 0)
    tilemap.create(json.at("size")[0], json.at("size")[0]);

  if (json.count("tiles") != 0)
    tilemap.setTiles(json.at("tiles"));

  if (json.count("permissions") != 0)
    tilemap.setPermissions(json.at("permissions"));
}