#ifndef _TILEMAP_READER_HPP
#define _TILEMAP_READER_HPP

#include "GameObject.hpp"
#include "Tilemap.hpp"
#include "TilesheetReader.hpp"

class TilemapReader : public GameObject {
public:
  static void read(Tilemap& tilemap, const std::string& filename);
  static void read(Tilemap& tilemap, std::ifstream& stream);

private:
  static const std::string kPrefix;
  static void readTilesheet(Tilemap& tilemap, std::ifstream& stream);
  static void readSize(Tilemap& tilemap, const std::string& line);
  static void readTiles(Tilemap& tilemap, std::ifstream& stream);
  static void readPermissions(Tilemap& tilemap, std::ifstream& stream);
};

#endif // _TILEMAP_READER_HPP