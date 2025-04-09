#pragma once
#include <stdarg.h>

class EErrorManager
{
    public:
        EErrorManager();
	    ~EErrorManager();

        void TraceMessagef(const char *format, ...);
};