#pragma once

class GameApp
{
    public:
        GameApp();
	    ~GameApp();

        bool StartUp(void *param_1);
        void Shutdown();

        bool InitFrame();
        bool RenderFrame();
        bool EndFrame();
};