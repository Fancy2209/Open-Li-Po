#include "EErrorManager.h"
#include <stdio.h>

EErrorManager::EErrorManager()
{
};

EErrorManager::~EErrorManager()
{
};

void EErrorManager::TraceMessagef(const char *format, ...)
{
    // TODO: This works, it is not accurate at all though
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
    fflush(stdout);
};