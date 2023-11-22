#include "CApp.h"

// The constructor (default)
CApp::CApp()
{
    // Set the running state to true
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
};

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    pWindow = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

    if (pWindow != NULL)
    {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

        m_image.Initialize(1280, 720, pRenderer);
    }
    else
    {
        return false;
    }

    return true;
}

int CApp::OnExecute()
{
    SDL_Event event;

    if (OnInit() == false)
    {
        return -1;
    }

    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }

    return 0;
};

void CApp::OnEvent(SDL_Event *event)
{
    if (event->type == SDL_QUIT)
    {
        isRunning = false;
    }
}

void CApp::OnLoop()
{
}

void CApp::OnRender()
{
    // Set the background color to white
    SDL_SetRenderDrawColor(pRenderer, 150, 55, 90, 255);
    SDL_RenderClear(pRenderer);

    // Render scene
    m_scene.Render(m_image);

    // Display the image
    m_image.Display();

    SDL_RenderPresent(pRenderer);
}

void CApp::OnExit()
{
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    pWindow = NULL;
    SDL_Quit();
}