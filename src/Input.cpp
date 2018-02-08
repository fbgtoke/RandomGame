#include "Input.hpp"

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

void Input::addOnPressedListener(Button button, std::function<void(void)> callback) {
  mOnPressed[button].push_back(callback);
}

void Input::addOnReleasedListener(Button button, std::function<void(void)> callback) {
  mOnReleased[button].push_back(callback);
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
    for (std::function<void(void)> callback : mOnPressed[button]) {
      callback();
    }
  }
}

void Input::triggerOnReleased(Button button) {
  if (button != NO_BUTTON) {
    for (std::function<void(void)> callback : mOnReleased[button]) {
      callback();
    }
  }
}
