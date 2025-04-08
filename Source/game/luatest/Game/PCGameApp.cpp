#include "PCGameApp.h"

PCGameApp::PCGameApp() : GameApp()
{
};

PCGameApp::~PCGameApp() 
{
};

bool PCGameApp::StartUp(void *param_1)
{
    // TODO: Steam Init Goes Here

    // TODO
    // _MoveOldSaves();

    //this->DetectCPUCaps(); // Was stubbed anyways

    if (!GameApp::StartUp(param_1))
    {
        return false;
    }

    /* SSE Code was never implemented in the Linux Port
    if (this->cpuCaps & 0x02000000)
    {
        this->bHasSSE = 1;
    }
    */

    return true;
}