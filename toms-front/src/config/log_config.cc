#include <include/common.h>

using namespace config;

LogConfig::LogConfig()
{
    this->home = nullptr;
}

LogConfig::~LogConfig()
{
    delete[] home;
}

void LogConfig::SetHome(const char *home)
{
    if (home != nullptr && home[0] != '\0')
    {
        char *tmp = new char[strlen(home) + 1];
        strcpy(tmp, home);
        this->home = tmp;
    }
}

const char *LogConfig::GetHome()
{
    return home;
}

void LogConfig::SetMaxFileSize(int size)
{
    this->maxFileSize = size;
}

int LogConfig::GetMaxFileSize()
{
    return maxFileSize;
}

void LogConfig::SetMaxMessageSize(int size)
{
    this->maxMessageSize = size;
}

int LogConfig::GetMaxMessageSize()
{
    return maxMessageSize;
}