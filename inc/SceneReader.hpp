#ifndef _SCENE_READER_HPP
#define _SCENE_READER_HPP

#include "SceneTest.hpp"

class SceneReader {
public:
  static void read(SceneTest* scene, const std::string& filename);
  static void read(SceneTest* scene, const Json& json);

private:
  static const std::string kPrefix;
};

#endif // _SCENE_READER_HPP