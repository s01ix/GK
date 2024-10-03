#ifndef ENGINE_H
#define ENGINE_H

#include <allegro5/allegro.h>

class Engine {
public:
    Engine();
    ~Engine();

    bool Init();  // Inicjalizacja Allegro
    void SetGraphicsMode(bool fullscreen, int width, int height);  // Tryb graficzny
    void Run();   // G³ówna pêtla gry
    void HandleEvents();  // Obs³uga zdarzeñ
    void ClearScreen(ALLEGRO_COLOR color);  // Czyszczenie ekranu
    void Shutdown();  // Zamykanie i sprz¹tanie

private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_BITMAP* buffer;
    bool running;
};

#endif

