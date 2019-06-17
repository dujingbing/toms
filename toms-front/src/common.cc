#include <unistd.h>
#include <include/common.h>
#include <deps/rapidjson/include/rapidjson/document.h>
#include <deps/rapidjson/include/rapidjson/writer.h>
#include <deps/rapidjson/include/rapidjson/stringbuffer.h>

using namespace log;
using namespace config;

Config::Config()
{
}

Config::~Config()
{
}

void Config::initialize()
{
    workDir = getcwd(NULL, 0);
    if (workDir == NULL)
    {
        perror("Toms-front server config error, cannot get current work directory.");
        exit(1);
    }
    //build configuration file path.
    char *configFile = new char[strlen(workDir) + strlen(config::Constant::CONFIG_FILE_NAME) + 1];
    sprintf(configFile, "%s%s", workDir, config::Constant::CONFIG_FILE_NAME);

    //read configuration.
}

ServerConfig *Config::GetServerConfig()
{
}

LogConfig *Config::GetLogConfig()
{
}

ServerConfig::ServerConfig()
{
}

ServerConfig::~ServerConfig()
{
}

void ServerConfig::SetPort()
{
}

int ServerConfig::GetPort()
{
}

void ServerConfig::SetMaxConnectionSize(int size)
{
}

int ServerConfig::GetMaxConnectionSize()
{
}

void Log::initialize(config::LogConfig *config)
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