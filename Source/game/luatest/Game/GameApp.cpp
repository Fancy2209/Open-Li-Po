#include "GameApp.h"
#include "UnixMain.h"

GameApp::GameApp() 
{

};

GameApp::~GameApp() 
{

};

bool GameApp::StartUp(void *param_1) 
{ 
    // EProfileOneShot::EProfileOneShot(local_d8,"Start Up");
    gGameApp = this;
    g_ErrorManager->SetEnabled(TT_ACTN, false);
    g_ErrorManager->SetEnabled(TT_SOUND, false);
    g_ErrorManager->SetEnabled(TT_CAM, false);
    g_ErrorManager->SetEnabled(TT_MESH, false);
    g_ErrorManager->SetEnabled(TT_ANIM, true);
    // ReadPrefs
    g_ErrorManager->SetEnabled(TT_STEAM, true);

    // TODO: Language Stuff

    // TODO: Console and Error Manager init
    
    // TODO: Unit Tests of DF Libs

    // TODO: Debug Manager init

    // this->InitInput(); // Stubbed in the game
    // this->ValidateGraphics(param_1); // Stubbed in the game
    this->InitRender(param_1);

    // TODO: All the fun stuff that happens after this to setup the scene
    // and the LuaVM 


    

    return true; 
};

void GameApp::Shutdown() 
{
    // TODO
};

void GameApp::InitRender(void *param1)
{
    m_pRenderer = new ERenderer;
    m_pRenderer->Init(param1, 0/*TODO*/);
    // TODO
}

bool GameApp::InitFrame() { 
    // TODO
    return true; 
};

bool GameApp::RenderFrame() { 
    // TODO
    return true; 
};

bool GameApp::EndFrame() { 
    // TODO
    return true; 
};