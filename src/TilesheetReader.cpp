#include "TilesheetReader.hpp"

void TilesheetReader::read(Tilesheet& tilesheet, const std::string& filename) {
  std::ifstream file(filename);

  if (file.is_open()) {
    read(tilesheet, file);
    file.close();
  } else {
    std::cout << "Could not load tilesheet " << filename << std::endl;
  }
}

void TilesheetReader::read(Tilesheet& tilesheet, std::ifstream& stream) {
  std::string line;

  while (getline(stream, line)) {
    if (line.find("texture") != std::string::npos) readTexture(tilesheet, line);
    else if (line.find("tileSize") != std::string::npos) readTileSize(tilesheet, line);
    else if (line.find("tilesPerRow") != std::string::npos) readTilesPerRow(tilesheet, line);
    else if (line.find("tileOffset") != std::string::npos) readTileOffset(tilesheet, line);
    else if (line.find("tileMargin") != std::string::npos) readTileMargin(tilesheet, line);
    else if (line.find("end") != std::string::npos) break;
  }
}

void TilesheetReader::readTexture(Tilesheet& tilesheet, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  std::string textureName;

  stream >> command >> textureName;
  tilesheet.useTexture(textureName);
}

void TilesheetReader::readTileSize(Tilesheet& tilesheet, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  unsigned int tileSize;

  stream >> command >> tileSize;
  tilesheet.setTileSize(tileSize);
}

void TilesheetReader::readTilesPerRow(Tilesheet& tilesheet, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  unsigned int tilesPerRow;

  stream >> command >> tilesPerRow;
  tilesheet.setTilesPerRow(tilesPerRow);
}

void TilesheetReader::readTileOffset(Tilesheet& tilesheet, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  sf::Vector2i offset;

  stream >> command >> offset.x >> offset.y;
  tilesheet.setTileOffset(offset);
}

void TilesheetReader::readTileMargin(Tilesheet& tilesheet, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  sf::Vector2i margin;

  stream >> command >> margin.x >> margin.y;
  tilesheet.setTileMargin(margin);
}