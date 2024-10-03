#ifndef POINT2D_H
#define POINT2D_H

#include<allegro5/allegro.h>

class PrimitiveRenderer;

class Point2D {
public:
    Point2D(float x, float y);
    float GetX() const;
    float GetY() const;
    void SetCoordinates(float x, float y);
    void Draw(PrimitiveRenderer& renderer,  ALLEGRO_COLOR color);

private:
    float x, y;
};

#endif
