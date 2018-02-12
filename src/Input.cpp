#include "Input.hpp"
#include "InputReader.hpp"
#include "GameObject.hpp"

Input::Input() {}

Input::~Input() {
  mKeyboardBindings.clear();
  mJoystickBindings.clear();

  for (int i = 0; i < NUM_BUTTONS; ++i) {
    mOnPressed[i].clear();
    mOnReleased[i].clear();
  }
}

void Input::processEvent(const sf::Event& event) {
  Button button = NO_BUTTON;

  switch (event.type) {
  case sf::Event::KeyPressed:
    button = keyboard2button(event.key.code);
    triggerOnPressed(button);
    break;
  case sf::Event::KeyReleased:
    button = keyboard2button(event.key.code);
    triggerOnReleased(button);
    break;
  case sf::Event::JoystickButtonPressed:
    button = joystick2button(event.joystickButton.button);
    triggerOnPressed(button);
    break;
  case sf::Event::JoystickButtonReleased:
    button = joystick2button(event.joystickButton.button);
    triggerOnReleased(button);
    break;
  default:
    break;
  }
}

void Input::addKeyboardBinding(sf::Keyboard::Key key, Button button) {
  mKeyboardBindings[key] = button;
}

void Input::addJoystickBinding(unsigned int key, Button button) {
  mJoystickBindings[key] = button;
}

void Input::addOnPressedListener(Button button, Listener listener) {
  mOnPressed[button].push_back(listener);
}

void Input::addOnReleasedListener(Button button, Listener listener) {
  mOnReleased[button].push_back(listener);
}

void Input::removeOnPressedListener(Button button, GameObject* object) {
  auto it = mOnPressed[button].begin();
  while (it != mOnPressed[button].end()) {
    if (it->listener == object)
      mOnPressed[button].erase(it++);
    else
      it++;
  }
}

void Input::removeOnReleasedListener(Button button, GameObject* object) {
  auto it = mOnReleased[button].begin();
  while (it != mOnReleased[button].end()) {
    if (it->listener == object)
      mOnReleased[button].erase(it++);
    else
      it++;
  }
}

Input::Button Input::keyboard2button(sf::Keyboard::Key key) const {
  if (mKeyboardBindings.count(key) != 0)
    return mKeyboardBindings.at(key);
  return NO_BUTTON;
}

Input::Button Input::joystick2button(unsigned int key) const {
  if (mJoystickBindings.count(key) != 0)
    return mJoystickBindings.at(key);
  return NO_BUTTON;
}

void Input::triggerOnPressed(Button button) {
  if (button != NO_BUTTON) {
    for (Listener& listener : mOnPressed[button]) {
      listener.callback();
    }
  }
}

void Input::triggerOnReleased(Button button) {
  if (button != NO_BUTTON) {
    for (Listener& listener : mOnReleased[button]) {
      listener.callback();
    }
  }
}

void Input::loadFromFile(const std::string& filename) {
  InputReader::read(*this, filename);
}