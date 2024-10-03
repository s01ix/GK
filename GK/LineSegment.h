#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "point2d.h"
#include "primitiverenderer.h"

class LineSegment {
public:
    LineSegment(const Point2D& start, const Point2D& end);
    Point2D GetStart() const;
    Point2D GetEnd() const;
    void SetStart(const Point2D& start);
    void SetEnd(const Point2D& end);
    void Draw(PrimitiveRenderer& renderer, ALLEGRO_COLOR color, bool useIncremental = false);

private:
    Point2D start, end;
};

#endif
