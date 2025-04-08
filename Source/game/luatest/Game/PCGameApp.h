#pragma once
#include "GameApp.h"

class PCGameApp: GameApp
{
    public:
        PCGameApp();
	    ~PCGameApp();

        void ParseCommandLine(int argc, char **argv);

        bool StartUp(void *param_1);
        void Shutdown();
        
        bool InitFrame();
        bool RenderFrame();
        bool EndFrame();
};