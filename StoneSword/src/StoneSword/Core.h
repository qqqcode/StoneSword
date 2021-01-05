#pragma once

#ifdef SS_PLATFROM_WINDOWS
	#ifdef SS_BUILD_DLL
		#define STONESWORD_API __declspec(dllexport)
	#else
		#define STONESWORD_API __declspec(dllimport)
	#endif // SS_BUILD_DLL0
#else
	#error StoneSword only supports Windows!
#endif // SS_PLATFROM_WINDOWS
