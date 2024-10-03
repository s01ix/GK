#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <allegro5/allegro_primitives.h>
#include <vector>
#include "point2d.h"

class PrimitiveRenderer {
public:
    void DrawLine(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness = 2.0);
    void DrawLineIncremental(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color);
    void DrawRectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color);
    void DrawCircle(float x, float y, float radius, ALLEGRO_COLOR color);
    void DrawPolyline(const std::vector<Point2D>& points, ALLEGRO_COLOR color, bool closed = false);
};

#endif
