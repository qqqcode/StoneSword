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

#ifdef SS_ENABLE_ASSERTS
	#define SS_ASSERT(x,...) { if(!(x)) { SS_ERROR("Assertion Failed: {0}",__VA_ARGS_); __debugbreak(); } }
	#define SS_CORE_ASSERT (x,...) { if(!(x)) { SS_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS_); __debugbreak(); } }
#else
	#define SS_ASSERT(x,...)
	#define SS_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1<<x)
