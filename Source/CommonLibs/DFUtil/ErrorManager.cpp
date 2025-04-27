#include "ErrorManager.h"
#include <cstdio>
#include <cstring>

int EErrorManager::sm_iInhibitDebugString = 0;

EErrorManager::EErrorManager()
{
	m_pConsoleCallback = nullptr;
	m_pNonFatalErrorHandler = nullptr;

	//TODO: Init shutdown callback EList
	//TODO: Init context callback EList

	//TODO: unknown field4_0x38

	m_TraceInfo[TT_GAME].m_pszName = "Game";
	m_TraceInfo[TT_WARN].m_pszName = "WARN";
	m_TraceInfo[TT_WARN2].m_pszName = "WARN";
	m_TraceInfo[TT_ERROR].m_pszName = "ERROR";
	m_TraceInfo[TT_LOC_WARN].m_pszName = "LOC WARN";
	m_TraceInfo[TT_PHYS].m_pszName = "Phys";
	m_TraceInfo[TT_ANIM].m_pszName = "Anim";
	m_TraceInfo[TT_REND].m_pszName = "Rend";
	m_TraceInfo[TT_VM].m_pszName = "VM  ";
	m_TraceInfo[TT_ACTN].m_pszName = "Actn";
	m_TraceInfo[TT_CAM].m_pszName = "Camera";
	m_TraceInfo[TT_SOUND].m_pszName = "Sound";
	m_TraceInfo[TT_MESH].m_pszName = "Mesh";
	m_TraceInfo[TT_PAUL].m_pszName = "Paul";
	m_TraceInfo[TT_JON].m_pszName = "Jon ";
	m_TraceInfo[TT_LANCE].m_pszName = "Lnce";
	m_TraceInfo[TT_DAVED].m_pszName = "DaveD";
	m_TraceInfo[TT_WILSON].m_pszName = "Wlsn";
	m_TraceInfo[TT_STEAM].m_pszName = "Steam";
};

EErrorManager::~EErrorManager()
{
}

void EErrorManager::SetEnabled(TRACETYPE traceType, bool bEnabled)
{
	m_TraceInfo[traceType].m_bEnabled = bEnabled;
}

void OutputDebugString(const char* pszString)
{
	if (pszString != nullptr && *pszString != '\0')
	{
		fputs(pszString, stderr);
	}
}

void EErrorManager::SafeOutputDebugString(const char* pszMessage)
{
	if (sm_iInhibitDebugString == 0)
	{
		OutputDebugString(pszMessage);
	}
	else
	{
		//TODO: EString::operator+=((EString *)sm_buf,param_1);
	}
}

void EErrorManager::TraceMessage(const char* pszMessage)
{
	if (m_pConsoleCallback == nullptr)
	{
		SafeOutputDebugString(pszMessage);
		SafeOutputDebugString("\n");
	}
	else
	{
		m_pConsoleCallback(pszMessage);
	}
}

void EErrorManager::TraceMessagef(TRACETYPE traceType, const char* pszMessage, ...)
{
	va_list args;
	va_start(args, pszMessage);
	TraceMessagev(traceType, pszMessage, args);
	va_end(args);
}

void EErrorManager::TraceMessagef(const char* pszMessage, ...)
{
	va_list args;
	va_start(args, pszMessage);
	TraceMessagev(TT_DEFAULT, pszMessage, args);
	va_end(args);
}

void EErrorManager::TraceMessagev(TRACETYPE traceType, const char* pszMessage, va_list args)
{
	if (!IsEnabled(traceType))
		return;

	char outBuf[1025];
	int len = 0;
	if (m_TraceInfo[traceType].m_pszName != nullptr)
	{
		strcpy(outBuf, m_TraceInfo[traceType].m_pszName);
		memcpy(outBuf + strlen(outBuf), ": ", 3);
		len = strlen(outBuf);
	}
	vsnprintf(outBuf + len, 1023 - len, pszMessage, args);
	outBuf[1024] = '\0';
	int end = strlen(outBuf);
	if (end != 0 && outBuf[end] == '\n')
	{
		outBuf[end] = '\0';
	}
	if (end != 0 && m_pNonFatalErrorHandler != nullptr)
	{
		m_pNonFatalErrorHandler(outBuf);
	}

	TraceMessage(outBuf);
}