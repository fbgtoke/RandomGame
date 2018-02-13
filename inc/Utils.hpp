#ifndef _UTILS_HPP
#define _UTILS_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <list>
#include <queue>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>

#include <json.hpp>
using Json = nlohmann::json;

const unsigned int kScreenWidth = 480;
const unsigned int kScreenHeight = 480;
const std::string kScreenTitle = "Title";

const unsigned int kFramerateLimit = 60;

enum Direction {
  Up = 0,
  Left,
  Right,
  Down,
  NUM_DIRS
};

template <class T>
float length(const sf::Vector2<T>& v) { return sqrt(v.x*v.x + v.y*v.y); }

template <class T>
sf::Vector2<T> normalize(const sf::Vector2<T>& v) {
  return v * float(1.f/length(v));
}

template <class T>
const sf::Vector2<T> v[] = {
  {  0, -1},
  { -1,  0},
  {  1,  0},
  {  0,  1}
};

template <class T>
sf::Vector2<T> dir2vec(Direction dir) { return v<T>[dir]; };

#endif // _UTILS_HPP