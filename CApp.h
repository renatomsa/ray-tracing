#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include "rayTracer/Image.hpp"
#include "rayTracer/scene.hpp"

class CApp
{
public:
    CApp();

    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event *event);
    void OnLoop();
    void OnRender();
    void OnExit();

private:
    // Instance of the image
    Image m_image;

    // Instance of the scene
    RT::Scene m_scene;

    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};

#endif