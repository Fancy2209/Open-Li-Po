#include "ERenderer.h"
#include "EOpenGLRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "UnixMain.h"
#define GL_GLEXT_PROTOTYPES

// ERenderer Implementation
ERenderer::ERenderer()
{
    // TODO
}

ERenderer::~ERenderer()
{
    // TODO
}


bool ERenderer::Init(void *hWnd, unsigned int param_2)
{
    g_pCurrentRenderer = this;
    return true;
};

bool ERenderer::initPlatform(void *hWnd, unsigned int param_2)
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        g_ErrorManager->TraceMessagef("SDL_Init() failed: %s\n", SDL_GetError());
    } else {
        SDL_GL_LoadLibrary(NULL);
        hWnd = SDL_CreateWindow(g_mainWindowCaption, 
                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                         640, 480, 
                         SDL_WINDOW_SHOWN
                        );
        SDL_SetWindowIcon((SDL_Window *)hWnd, SDL_LoadBMP_RW(SDL_RWFromFile("icon.bmp", "rb"), true));
    }
    return true;
};

EOpenGLRenderer::EOpenGLRenderer()
{
}

EOpenGLRenderer::~EOpenGLRenderer()
{
}