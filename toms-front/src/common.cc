#include <unistd.h>
#include <include/common.h>
#include <deps/rapidjson/include/rapidjson/document.h>
#include <deps/rapidjson/include/rapidjson/writer.h>
#include <deps/rapidjson/include/rapidjson/stringbuffer.h>

using namespace log;
using namespace config;
using namespace files;

Config::Config()
{
}

Config::~Config()
{
}

bool Config::initialize(const char *configFile)
{
    //read configuration.

}

HttpServerConfig *Config::GetHttpServerConfig()
{
}

LogConfig *Config::GetLogConfig()
{
}

HttpServerConfig::HttpServerConfig()
{
}

HttpServerConfig::~HttpServerConfig()
{
}

void HttpServerConfig::SetPort(int port)
{
}

int HttpServerConfig::GetPort()
{
}

void HttpServerConfig::SetMaxConnectionSize(int size)
{
}

int HttpServerConfig::GetMaxConnectionSize()
{
}

ProtoServerConfig::ProtoServerConfig()
{
}

ProtoServerConfig::~ProtoServerConfig()
{
}

void ProtoServerConfig::SetPort(int port)
{
}

int ProtoServerConfig::GetPort()
{
}

bool Log::initialize(config::LogConfig *config)
{
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

bool FileUtils::exist(const char *path)
{
    if (path == nullptr)
    {
        return false;
    }
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return false;
    }
    else
    {
        fclose(file);
        return true;
    }
}