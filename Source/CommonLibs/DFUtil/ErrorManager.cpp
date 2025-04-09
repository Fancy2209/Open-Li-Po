#include "EErrorManager.h"
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

	m_TraceInfo[GAME].m_pszName = "Game";
	m_TraceInfo[WARN].m_pszName = "WARN";
	m_TraceInfo[WARN2].m_pszName = "WARN";
	m_TraceInfo[ERROR].m_pszName = "ERROR";
	m_TraceInfo[LOC_WARN].m_pszName = "LOC WARN";
	m_TraceInfo[PHYS].m_pszName = "Phys";
	m_TraceInfo[ANIM].m_pszName = "Anim";
	m_TraceInfo[REND].m_pszName = "Rend";
	m_TraceInfo[VM].m_pszName = "VM  ";
	m_TraceInfo[ACTN].m_pszName = "Actn";
	m_TraceInfo[CAM].m_pszName = "Camera";
	m_TraceInfo[SOUND].m_pszName = "Sound";
	m_TraceInfo[MESH].m_pszName = "Mesh";
	m_TraceInfo[PAUL].m_pszName = "Paul";
	m_TraceInfo[JON].m_pszName = "Jon ";
	m_TraceInfo[LANCE].m_pszName = "Lnce";
	m_TraceInfo[DAVED].m_pszName = "DaveD";
	m_TraceInfo[WILSON].m_pszName = "Wlsn";
	m_TraceInfo[STEAM].m_pszName = "Steam";
};

EErrorManager::~EErrorManager()
{
}

void EErrorManager::SetEnabled(TRACETYPE traceType, bool bEnabled)
{
	m_TraceInfo[traceType].m_bEnabled = bEnabled;
}

void OutputDebugString(char* pszString)
{
	if (pszString != nullptr && *pszString != '\0')
	{
		fputs(pszString, stderr);
	}
}

void EErrorManager::SafeOutputDebugString(char* pszMessage)
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

void EErrorManager::TraceMessage(char* pszMessage)
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

void EErrorManager::TraceMessagef(TRACETYPE traceType, char* pszMessage, ...)
{
	va_list args;
	va_start(args, pszMessage);
	TraceMessagev(traceType, pszMessage, args);
	va_end(args);
}

void EErrorManager::TraceMessagef(char* pszMessage, ...)
{
	va_list args;
	va_start(args, pszMessage);
	TraceMessagev(DEFAULT, pszMessage, args);
	va_end(args);
}

void EErrorManager::TraceMessagev(TRACETYPE traceType, char* pszMessage, va_list args)
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