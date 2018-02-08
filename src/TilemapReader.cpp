#include "TilemapReader.hpp"

void TilemapReader::read(Tilemap& tilemap, const std::string& filename) {
  std::ifstream file(filename);

  if (file.is_open()) {
    readTilesheet(tilemap, file);
    readTilemap(tilemap, file);
    file.close();
  } else {
    std::cout << "Could not load tilemap " << filename << std::endl;
  }
}

void TilemapReader::readTilesheet(Tilemap& tilemap, std::ifstream& file) {
  std::string textureName;
  unsigned int tileSize;
  unsigned int tilesPerRow;
  sf::Vector2i tileOffset;
  sf::Vector2i tileMargin;

  file
    >> textureName
    >> tileSize
    >> tilesPerRow
    >> tileOffset.x >> tileOffset.y
    >> tileMargin.x >> tileMargin.y;

  Tilesheet& tilesheet = tilemap.getTilesheet();
  tilesheet.useTexture(textureName);
  tilesheet.setTileSize(tileSize);
  tilesheet.setTilesPerRow(tilesPerRow);
  tilesheet.setTileOffset(tileOffset);
  tilesheet.setTileMargin(tileMargin);
}

void TilemapReader::readTilemap(Tilemap& tilemap, std::ifstream& file) {
  unsigned int width;
  unsigned int height;

  file >> width >> height;
  tilemap.create(width, height);

  unsigned int value;
  for (unsigned int i = 0; i < height; ++i) {
    for (unsigned int j = 0; j < width; ++j) {
      file >> value;
      tilemap.setTile(j, i, value);
    }
  }
}