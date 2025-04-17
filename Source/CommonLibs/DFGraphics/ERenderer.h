#pragma once

class ERenderer
{
    private:
        ERenderer *g_pCurrentRenderer;
    public:
        ERenderer();
        ~ERenderer();
        bool Init(void *hWnd, unsigned int param_2);
        bool initPlatform(void *hWnd, unsigned int param_2);
};