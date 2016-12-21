#include "Button.h"
#include "Point.h"
#include "Callbacks.h"
#include <vector>
#include <string>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

Button::Button()
{
    cout << "empty button init called\n";
}

Button::Button(float x, float y, float w, float h, string label, void (Callbacks::*callBack_func)(), Callbacks* callbacks, int objRef)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->label = label;
    this->isClicked = false;
    this->objRef = objRef;
    this->callBack_func = callBack_func;
    this->callbacks = callbacks;
    this->makeGeometry();
    }

void Button::whoami()
{
        cout << "i am " << label << "\n";
}

void Button::drawButton()
{
    float color[4];
    glPushMatrix();
        glTranslatef(this->x, this->y, 0.0f);
        glPushMatrix();
            glScalef(this->w, this->h, 0.0f);
            glLoadName(this->objRef);
            glBegin(GL_POLYGON);
            for (int i = 0; i < 4; i++) {
                float vec[2];
                vec[0] = geometry[i].getPoint()[0];
                vec[1] = geometry[i].getPoint()[1];

                glVertex2fv(vec);
            }
            glEnd();
            if (this->isClicked) {
                glGetFloatv(GL_CURRENT_COLOR, color);
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 4; i++) {
                    float vec[2];
                    vec[0] = geometry[i].getPoint()[0];
                    vec[1] = geometry[i].getPoint()[1];

                    glVertex2fv(vec);
                }
                glEnd();
                glColor3f(color[0], color[1], color[2]);
            }
        glPopMatrix();
        glGetFloatv(GL_CURRENT_COLOR, color);
        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 0.0f);
            glScalef(0.1, 0.1, 0.0);

            int width = 0;
            for (int i = 0; i < this->label.size(); i++)
                width += glutStrokeWidth(GLUT_STROKE_ROMAN, this->label[i]);

            glTranslatef(-width / 2, 0.0, 0.0f);
            glColor3f(0.0f, 1.0f, 1.0f);
            for (int i = 0; i < this->label.size(); i++) {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, this->label[i]);
            }
        glPopMatrix();
        glColor3f(color[0], color[1], color[2]);
    glPopMatrix();
}

void Button::makeGeometry()
{
    this->geometry.push_back(Point(-0.5f, -0.5f));
    this->geometry.push_back(Point(-0.5f, 0.5f));
    this->geometry.push_back(Point(0.5f, 0.5f));
    this->geometry.push_back(Point(0.5f, -0.5f));
}

void Button::callBack()
{
    if (callBack_func)
        (callbacks->*callBack_func)();
}
