#include "SDL2/SDL.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _WIN32
#include <unistd.h> // getcwd
#else
#include <direct.h> // _getcwd
#endif
#include "UnixMain.h"

PCGameApp *gpApp;
EFileManager *gFile_dfutil = new EFileManager;
//EErrorManager *g_ErrorManager = new EErrorManager;
void *g_pEmergencyMemory;
const char *g_mainWindowCaption;
const char *g_mainWindowCaptionSmall;
const char *skInstallPackageVersionFilename = "PsychonautsData2.pkg";
int g_iReturnValue;
bool g_bWMQuitReceived;


void sdlquit(void)

{
  SDL_Quit();
  return;
}


bool PCMainHandleAnyWindowsMessages()
{
  SDL_Event event;
  
  int iVar1 = SDL_PollEvent(&event);
  if (event.type == SDL_QUIT) {
      g_bWMQuitReceived = true;
      g_iReturnValue = 0;
    }
  return g_bWMQuitReceived;
}


int main(int argc, char **argv) {
  bool shouldRun;
  char cwdBuf[4096];
  int currentArg = 1;

  while (true) {
    if (argc <= currentArg) {
      atexit(sdlquit);
      //chdirToAppPath(argv[0]); // Impl is a problem for the future
      //SetPCLanguage(0); // was stubbed anyway
      g_pEmergencyMemory = malloc(0xc000);
      g_mainWindowCaption = "Psychonauts";
      g_mainWindowCaptionSmall = "psychonauts";
      gFile_dfutil->AddReadPath("WorkResource", false);
      gFile_dfutil->AddReadPath("TestResource", false);
      gFile_dfutil->SetWritePath("WorkResource");
      gFile_dfutil->AddFilePackage(skInstallPackageVersionFilename);
      gpApp = new PCGameApp;
      gpApp->ParseCommandLine(argc, argv);
      bool wasStartupSuccessful = gpApp->StartUp(NULL);
      if (wasStartupSuccessful != false) {
        // g_ErrorManager->TraceMessagef("UnixMain: StartUp successful..");
        printf("UnixMain: StartUp successful..");
#ifndef __WIN32__
        if (getcwd(cwdBuf, 4096) == NULL) {
#else
        if (_getcwd(cwdBuf, 4096) == NULL) {
#endif
          // g_ErrorManager->TraceMessagef("Unable to get working directory!");
          printf("Unable to get working directory!");
          snprintf(cwdBuf, 4096, "unknown");
        }
        // g_ErrorManager->TraceMessagef("Working directory: %s", cwdBuf);
        printf("Working directory: %s", cwdBuf);
        while (true) {
          if (PCMainHandleAnyWindowsMessages() == true || g_iReturnValue == 1) {
            shouldRun = false;
          } else {
            shouldRun = true;
          }
          if (!shouldRun)
            break;
          // Inherited from GameApp
          gpApp->InitFrame();
          gpApp->RenderFrame();
          gpApp->EndFrame();
        }
        g_iReturnValue = 1;
      }
      // Inherited from GameApp
      gpApp->Shutdown();
      if (gpApp != NULL) {
        delete gpApp;
      }
      return g_iReturnValue;
    }
    if (strcmp(argv[currentArg], "-v") == 0)
      break;
    currentArg++;
  }
  printf("Psychonauts Version: %c%d.%d\n", 0x50, 602, 0);
  return 0;
}


