#include <unistd.h>
#include <include/common.h>

using namespace log;
using namespace config;
using namespace files;

bool Log::initialize(config::LogConfig *config)
{
    if (config == nullptr)
    {
        return false;
    }
}

void Log::Info(const char *file, const char *message, ...)
{
}

void Log::Debug(const char *file, const char *message, ...)
{
}

void Log::Warn(const char *file, const char *message, ...)
{
}

void Log::Error(const char *file, const char *message, ...)
{
}