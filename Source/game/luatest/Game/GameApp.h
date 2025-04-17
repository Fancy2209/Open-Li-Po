#pragma once
#include "DFGraphics/ERenderer.h"

class GameApp
{
private:
    GameApp *gGameApp;
    ERenderer *m_pRenderer;

public:
    GameApp();
    ~GameApp();

    bool StartUp(void *param_1);
    void Shutdown();

    void InitRender(void *param_1);
    bool InitFrame();
    bool RenderFrame();
    bool EndFrame();
};