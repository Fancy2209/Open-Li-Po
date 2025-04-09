#pragma once
#include <stdarg.h>

#include <stdarg.h>

enum TRACETYPE
{
	DEFAULT  = 0,
	UNKNOWN, //TODO
	GAME,
	WARN,
	WARN2, //TODO
	ERROR,
	LOC_WARN,
	PHYS,
	ANIM,
	REND,
	VM,
	ACTN,
	CAM,
	SOUND,
	MESH,
	PAUL,
	JON,
	LANCE,
	DAVED,
	WILSON,
	STEAM,

	TRACE_MAX
};

typedef void (*NonFatalErrorHandler)(char* pszMessage);
typedef void (*ConsoleCallback)(char* pszMessage);
typedef void (*ContextCallback)(void);
typedef void (*ShutdownCallback)(void);

class EErrorManager
{
	private:
		static int sm_iInhibitDebugString;

		class FTraceInfo
		{
		public:
			char* m_pszName;
			bool m_bEnabled;

			FTraceInfo()
			{
				m_pszName = nullptr;
				m_bEnabled = true;
			};
		};

		ConsoleCallback m_pConsoleCallback;
		NonFatalErrorHandler m_pNonFatalErrorHandler;

		FTraceInfo m_TraceInfo[TRACE_MAX];

		bool IsEnabled(TRACETYPE traceType)
		{
			return m_TraceInfo[traceType].m_bEnabled;
		}

    public:
		EErrorManager();
	    ~EErrorManager();

		void SetEnabled(TRACETYPE traceType, bool bEnabled);

		void SafeOutputDebugString(char* pszMessage);

		void TraceMessage(char* pszMessage);
        void TraceMessagef(TRACETYPE traceType, char* pszMessage, ...);
        void TraceMessagef(char* pszMessage, ...);
		void TraceMessagev(TRACETYPE traceType, char* pszMessage, va_list args);
};