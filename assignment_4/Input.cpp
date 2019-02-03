//
// Created by mustafa paslı on 23.04.2018.
//

#include "Input.h"

void Input::setInputValue(bool inputValue) {
    Input::inputValue = inputValue;
}

Input::Input(string name) : inputValue(false) {
    setOutput1(name);
}

bool Input::calculate() {
    return inputValue;
}
