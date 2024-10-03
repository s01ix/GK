#ifndef ENGINE_H
#define ENGINE_H

#include <allegro5/allegro.h>

class Engine {
public:
    Engine();
    ~Engine();

    bool Init();  // Inicjalizacja Allegro
    void SetGraphicsMode(bool fullscreen, int width, int height);  // Tryb graficzny
    void Run();   // G��wna p�tla gry
    void HandleEvents();  // Obs�uga zdarze�
    void ClearScreen(ALLEGRO_COLOR color);  // Czyszczenie ekranu
    void Shutdown();  // Zamykanie i sprz�tanie

private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_BITMAP* buffer;
    bool running;
};

#endif

