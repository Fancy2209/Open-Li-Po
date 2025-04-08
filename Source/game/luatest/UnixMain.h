#include "DFUtil/EFileManager.h"
#include "DFUtil/EErrorManager.h"
#include "Game/PCGameApp.h"

extern PCGameApp *gpApp;
extern EFileManager *gFile_dfutil;
//extern EErrorManager *g_ErrorManager; // TODO: Actually implement the EErrorManager instead of using printf
extern void *g_pEmergencyMemory;
extern const char *g_mainWindowCaption;
extern const char *g_mainWindowCaptionSmall;
extern const char *skInstallPackageVersionFilename;
extern int g_iReturnValue;
extern bool g_bWMQuitReceived;