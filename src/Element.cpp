#include "Element.h"

Element::Element()
{
    lineWeight = 2.0;
    lineColor = Color();
    fillColor = Color();
    isFilled = true;
}

void Element::setIsFilled(bool b)
{
    this->isFilled = b;
}

void Element::setLineColor(Color c)
{
    this->lineColor = c;
}

void Element::setFillColor(Color c)
{
    this->fillColor = c;
}

void Element::setLineWeight(float weight)
{
    this->lineWeight = weight;
}

bool Element::getIsFilled()
{
    return this->isFilled;
}

float Element::getLineWeight()
{
    return this->lineWeight;
}

Color Element::getLineColor()
{
    return this->lineColor;
}

Color Element::getFillColor()
{
    return this->fillColor;
}