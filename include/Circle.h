#pragma once

#include "Shape.h"
#include "Element.h"
#include <cmath>
#define PI 3.14159265


class Circle : public Shape {
public:
    Circle(Point p, int width, int height, int objRef, Element e) : Shape(p, width, height, objRef, e){
        int theta = 0;  // angle that will be increased each loop
        int step = 5;  // amount to add to theta each time (degrees)

        while (theta < 360) {
            float x = 0.5f*cos(theta * PI / 180);
            float y = 0.5f*sin(theta * PI / 180);
            this->geometry.push_back(Point(x, y));
            theta += step;
        }
    }
private:
};
