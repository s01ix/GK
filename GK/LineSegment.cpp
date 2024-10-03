#include "linesegment.h"

LineSegment::LineSegment(const Point2D& _start, const Point2D& _end) : start(_start), end(_end) {}

Point2D LineSegment::GetStart() const {
    return start;
}

Point2D LineSegment::GetEnd() const {
    return end;
}

void LineSegment::SetStart(const Point2D& _start) {
    start = _start;
}

void LineSegment::SetEnd(const Point2D& _end) {
    end = _end;
}

void LineSegment::Draw(PrimitiveRenderer& renderer, ALLEGRO_COLOR color, bool useIncremental) {
    if (useIncremental) {
        renderer.DrawLineIncremental(start.GetX(), start.GetY(), end.GetX(), end.GetY(), color);
    }
    else {
        renderer.DrawLine(start.GetX(), start.GetY(), end.GetX(), end.GetY(), color);
    }
}
