#include "ERenderer.h"
#include "EOpenGLRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#define GL_GLEXT_PROTOTYPES

ERenderer::ERenderer()
{
}

ERenderer::~ERenderer()
{
}

bool ERenderer::initPlatform(void *hWnd, unsigned int param_2)
{
};

EOpenGLRenderer::EOpenGLRenderer()
{
}

EOpenGLRenderer::~EOpenGLRenderer()
{
}