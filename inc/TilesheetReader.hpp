#ifndef _TILESHEET_READER_HPP
#define _TILESHEET_READER_HPP

#include "GameObject.hpp"
#include "Tilesheet.hpp"

class TilesheetReader : public GameObject {
public:
  static void read(Tilesheet& tilesheet, const std::string& filename);
  static void read(Tilesheet& tilesheet, std::ifstream& stream);

private:
  static void readTexture(Tilesheet& tilesheet, const std::string& line);
  static void readTileSize(Tilesheet& tilesheet, const std::string& line);
  static void readTilesPerRow(Tilesheet& tilesheet, const std::string& line);
  static void readTileOffset(Tilesheet& tilesheet, const std::string& line);
  static void readTileMargin(Tilesheet& tilesheet, const std::string& line);
};

#endif // _TILESHEET_READER_HPP