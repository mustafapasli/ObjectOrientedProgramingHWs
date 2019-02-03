//
// Created by mustafa paslı on 6.04.2018.
//

#include "Element.h"

int Element::getIndex() const {
    return index;
}

void Element::setIndex(int index) {
    Element::index = index;
}

double Element::getData() const {
    return data;
}

void Element::setData(double data) {
    Element::data = data;
}

int Element::getLineNumber() const {
    return lineNumber;
}

void Element::setLineNumber(int lineNumber) {
    Element::lineNumber = lineNumber;
}
