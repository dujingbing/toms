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
    if (!files::FileUtils::Exist(config->GetHome()))
    {
        return false;
    }
    if (config->GetMaxFileSize() > 512)
    {
        //max file size 512MB.
        config->SetMaxFileSize(512);
    }
    if (config->GetMaxFileSize() < 5)
    {
        //min file size 5MB.
        config->SetMaxFileSize(5);
    }
    return true;
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