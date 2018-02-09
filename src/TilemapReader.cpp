#include "TilemapReader.hpp"

const std::string TilemapReader::kPrefix = "res/tilemaps/";

void TilemapReader::read(Tilemap& tilemap, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  if (file.is_open()) {
    read(tilemap, file);
    file.close();
  } else {
    std::cout << "Could not load tilemap " << filename << std::endl;
  }
}

void TilemapReader::read(Tilemap& tilemap, std::ifstream& stream) {
  std::string line;

  while (getline(stream, line)) {
    if (line.find("tilesheet") != std::string::npos) readTilesheet(tilemap, stream);
    else if (line.find("size") != std::string::npos) readSize(tilemap, line);
    else if (line.find("tiles") != std::string::npos) readTiles(tilemap, stream);
    else if (line.find("permissions") != std::string::npos) readPermissions(tilemap, stream);
  }
}

void TilemapReader::readTilesheet(Tilemap& tilemap, std::ifstream& stream) {
  TilesheetReader::read(tilemap.getTilesheet(), stream);
}

void TilemapReader::readSize(Tilemap& tilemap, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  unsigned int width;
  unsigned int height;

  stream >> command >> width >> height;

  tilemap.create(width, height);
}

void TilemapReader::readTiles(Tilemap& tilemap, std::ifstream& stream) {
  unsigned int value;
  for (unsigned int i = 0; i < tilemap.getHeight(); ++i) {
    for (unsigned int j = 0; j < tilemap.getWidth(); ++j) {
      stream >> value;
      tilemap.setTile(j, i, value);
    }
  }
}

void TilemapReader::readPermissions(Tilemap& tilemap, std::ifstream& stream) {
  unsigned int value;
  for (unsigned int i = 0; i < tilemap.getHeight(); ++i) {
    for (unsigned int j = 0; j < tilemap.getWidth(); ++j) {
      stream >> value;
      tilemap.setPermission(j, i, value);
    }
  }
}