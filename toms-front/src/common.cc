#include <include/common.h>

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

const char *Constant::SERVER_LOG = "server.log";
const char *Constant::ROUTE_LOG = "route.log";
const char *Constant::CONFIG_LOG = "config.log";