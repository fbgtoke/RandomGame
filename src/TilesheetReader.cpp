#include "TilesheetReader.hpp"

void TilesheetReader::read(Tilesheet& tilesheet, const std::string& filename) {
  std::ifstream file(filename);
  
  std::string content;
  std::stringstream ss;
  Json json;

  if (file.is_open()) {
    content.assign( (std::istreambuf_iterator<char>(file) ),
                    (std::istreambuf_iterator<char>()    ) );
    
    ss << content;
    ss >> json;
    read(tilesheet, json);

    file.close();
  } else {
    std::cout << "Could not load tilesheet " << filename << std::endl;
  }
}

void TilesheetReader::read(Tilesheet& tilesheet, const Json& json) {
  if (json.count("texture") != 0)
    tilesheet.useTexture(json.at("texture"));
  if (json.count("tileSize") != 0)
    tilesheet.setTileSize(json.at("tileSize"));
  if (json.count("tilesPerRow") != 0)
    tilesheet.setTilesPerRow(json.at("tilesPerRow"));
  if (json.count("tileOffset") != 0)
    tilesheet.setTileOffset(json.at("tileOffset")[0], json.at("tileOffset")[1]);
  if (json.count("tileMargin") != 0)
    tilesheet.setTileMargin(json.at("tileMargin")[0], json.at("tileMargin")[1]);
}