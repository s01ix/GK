//engine.cpp
#include "engine.h"
#include "LineSegment.h"
#include "point2d.h"
#include "PrimitiveRenderer.h"
#include <iostream>

Engine::Engine() : display(nullptr), event_queue(nullptr), running(false) {}

Engine::~Engine() {
    Shutdown();
}

bool Engine::Init() {
    if (!al_init()) {
        std::cerr << "Nie uda³o siê zainicjowaæ Allegro!" << std::endl;
        return false;
    }
    if (!al_install_keyboard()) {
        std::cerr << "Nie uda³o siê zainstalowaæ klawiatury!" << std::endl;
        return false;
    }
    if (!al_install_mouse()) {
        std::cerr << "Nie uda³o siê zainstalowaæ myszy!" << std::endl;
        return false;
    }
    event_queue = al_create_event_queue();
    if (!event_queue) {
        std::cerr << "Nie uda³o siê stworzyæ kolejki zdarzeñ!" << std::endl;
        return false;
    }

    buffer = al_create_bitmap(1280, 720);
    if (!buffer) {
        std::cerr << "Nie uda³o siê stworzyæ bufora!" << std::endl;
        return false;
    }


    return true;
}

void Engine::SetGraphicsMode(bool fullscreen, int width, int height) {
    if (fullscreen) {
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    }
    else {
        al_set_new_display_flags(ALLEGRO_WINDOWED);
    }
    display = al_create_display(width, height);
    if (!display) {
        std::cerr << "Nie uda³o siê stworzyæ okna!" << std::endl;
        running = false;
    }
}

void Engine::Run() {
    running = true;

    // Inicjalizacja renderera i obiektu LineSegment
    PrimitiveRenderer renderer;
    Point2D start(100, 100);
    Point2D end(300, 300);
    LineSegment line(start, end);

    while (running) {
        HandleEvents();

        // Rysowanie na buforze
        al_set_target_bitmap(buffer);
        ClearScreen(al_map_rgb(0, 0, 255));  // Czyszczenie bufora na niebiesko

        // Rysowanie linii o gruboœci np. 5.0
        line.Draw(renderer, al_map_rgb(255, 255, 255));  // Bia³a linia
        renderer.DrawLine(start.GetX(), start.GetY(), end.GetX(), end.GetY(), al_map_rgb(255, 255, 255), 5.0);  // U¿ycie grubszej linii

        // Ustawienie celu na g³ówny bufor ekranu
        al_set_target_backbuffer(display);
        al_draw_bitmap(buffer, 0, 0, 0);  // Przeniesienie bufora na ekran

        al_flip_display();  // Aktualizacja ekranu
        al_rest(0.016);  // Odpoczynek (ok. 60 klatek na sekundê)
    }
}


void Engine::HandleEvents() {
    ALLEGRO_EVENT ev;
    while (al_get_next_event(event_queue, &ev)) {
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
    }
}

void Engine::ClearScreen(ALLEGRO_COLOR blue) {
    al_clear_to_color(blue);
}

void Engine::Shutdown() {
    if (display) {
        al_destroy_display(display);
        display = nullptr;
    }
    if (event_queue) {
        al_destroy_event_queue(event_queue);
        event_queue = nullptr;
    }
    al_uninstall_keyboard();
    al_uninstall_mouse();
}
