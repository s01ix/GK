#include "point2d.h"
#include "PrimitiveRenderer.h"

#include<allegro5/allegro.h>
Point2D::Point2D(float _x, float _y) : x(_x), y(_y) {}

float Point2D::GetX() const {
    return x;
}

float Point2D::GetY() const {
    return y;
}

void Point2D::SetCoordinates(float _x, float _y) {
    x = _x;
    y = _y;
}

void Point2D::Draw(PrimitiveRenderer& renderer, ALLEGRO_COLOR color) {
    renderer.DrawCircle(x, y, 2.0, color);  
}
