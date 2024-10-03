//primitverenderer.cpp
#include "primitiverenderer.h"

void PrimitiveRenderer::DrawLine(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness) {
    al_draw_line(x1, y1, x2, y2, color, thickness);
}



void PrimitiveRenderer::DrawLineIncremental(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color) {
}

void PrimitiveRenderer::DrawRectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color) {
    al_draw_rectangle(x1, y1, x2, y2, color, 2.0);
}

void PrimitiveRenderer::DrawCircle(float x, float y, float radius, ALLEGRO_COLOR color) {
    al_draw_circle(x, y, radius, color, 2.0);
}

void PrimitiveRenderer::DrawPolyline(const std::vector<Point2D>& points, ALLEGRO_COLOR color, bool closed) {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        DrawLine(points[i].GetX(), points[i].GetY(), points[i + 1].GetX(), points[i + 1].GetY(), color);
    }
    if (closed) {
        DrawLine(points.back().GetX(), points.back().GetY(), points.front().GetX(), points.front().GetY(), color);
    }
}
