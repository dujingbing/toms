#include <include/common.h>

using namespace log;

Log::Log()
{
}

Log::Log(const char *home)
{
}

Log::~Log()
{
}

void Log::Info(const char *message, ...)
{
}

void Log::Info(const char *file, const char *message, ...)
{
}

void Log::Debug(const char *message, ...)
{
}

void Log::Debug(const char *file, const char *message, ...)
{
}

void Log::Warn(const char *message, ...)
{
}

void Log::Warn(const char *file, const char *message, ...)
{
}

void Log::Error(const char *message, ...)
{
}

void Log::Error(const char *file, const char *message, ...)
{
}

const char *Constant::SERVER_LOG = "server.log";
const char *Constant::ROUTE_LOG = "route.log";
const char *Constant::CONFIG_LOG = "config.log";