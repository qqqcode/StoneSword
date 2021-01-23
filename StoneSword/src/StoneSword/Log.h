#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace StoneSword {
	class STONESWORD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


#define SS_CORE_TRACE(...)		::StoneSword::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define SS_CORE_INFO(...)		::StoneSword::Log::GetCoreLogger()->info(__VA_ARGS__);
#define SS_CORE_WARN(...)		::StoneSword::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define SS_CORE_ERROR(...)		::StoneSword::Log::GetCoreLogger()->error(__VA_ARGS__);
#define SS_CORE_FATAL(...)		::StoneSword::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define SS_TRACE(...)			::StoneSword::Log::GetClientLogger()->trace(__VA_ARGS__);
#define SS_INFO(...)			::StoneSword::Log::GetClientLogger()->info(__VA_ARGS__);
#define SS_WARN(...)			::StoneSword::Log::GetClientLogger()->warn(__VA_ARGS__);
#define SS_ERROR(...)			::StoneSword::Log::GetClientLogger()->error(__VA_ARGS__);
#define SS_FATAL(...)			::StoneSword::Log::GetClientLogger()->fatal(__VA_ARGS__);