#ifndef _DLLSETTING_
#define _DLLSETTING_

#ifdef DLL_EXPORT
#define SERVER_API __declspec(dllexport)
#else
#define SERVER_API __declspec(dllimport)
#endif

#endif