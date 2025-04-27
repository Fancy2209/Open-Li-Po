#pragma once
#include <stdarg.h>

enum TRACETYPE
{
	TT_DEFAULT  = 0,
	TT_UNKNOWN, //TODO
	TT_GAME,
	TT_WARN,
	TT_WARN2, //TODO
	TT_ERROR,
	TT_LOC_WARN,
	TT_PHYS,
	TT_ANIM,
	TT_REND,
	TT_VM,
	TT_ACTN,
	TT_CAM,
	TT_SOUND,
	TT_MESH,
	TT_PAUL,
	TT_JON,
	TT_LANCE,
	TT_DAVED,
	TT_WILSON,
	TT_STEAM,

	TRACE_MAX
};

typedef void (*NonFatalErrorHandler)(const char* pszMessage);
typedef void (*ConsoleCallback)(const char* pszMessage);
typedef void (*ContextCallback)(void);
typedef void (*ShutdownCallback)(void);

class EErrorManager
{
	private:
		static int sm_iInhibitDebugString;

		class FTraceInfo
		{
		public:
			const char* m_pszName;
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

		void SafeOutputDebugString(const char* pszMessage);

		void TraceMessage(const char* pszMessage);
        void TraceMessagef(TRACETYPE traceType, const char* pszMessage, ...);
        void TraceMessagef(const char* pszMessage, ...);
		void TraceMessagev(TRACETYPE traceType, const char* pszMessage, va_list args);
};