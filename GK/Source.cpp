#include "engine.h"
#include "primitiverenderer.h"
#include "point2d.h"
#include "linesegment.h"
#include <allegro5/allegro.h>

int main() {
    Engine engine;

    if (!engine.Init()) {
        return -1;
    }

    engine.SetGraphicsMode(false, 1280, 720);

    engine.Run();  

    engine.Shutdown();

    return 0;
}
