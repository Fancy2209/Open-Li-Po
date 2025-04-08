#pragma once

class GameApp
{
    public:
        GameApp(){};
	    ~GameApp(){};

        bool StartUp(void *param_1){return true;};
        void Shutdown(){};

        bool InitFrame(){return true;};
        bool RenderFrame(){return true;};
        bool EndFrame(){return true;};
};