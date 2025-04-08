#include "GameApp.h"

GameApp::GameApp() {};
GameApp::~GameApp() {};
bool GameApp::StartUp(void *param_1) { return true; };
void GameApp::Shutdown() {};
bool GameApp::InitFrame() { return true; };
bool GameApp::RenderFrame() { return true; };
bool GameApp::EndFrame() { return true; };