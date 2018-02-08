#ifndef _TILEMAP_READER_HPP
#define _TILEMAP_READER_HPP

#include "GameObject.hpp"
#include "Tilemap.hpp"

class TilemapReader : public GameObject {
public:
  static void read(Tilemap& tilemap, const std::string& filename);

private:
  static void readTilesheet(Tilemap& tilemap, std::ifstream& file);
  static void readTilemap(Tilemap& tilemap, std::ifstream& file);
};

#endif // _TILEMAP_READER_HPP