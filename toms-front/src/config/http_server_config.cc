#include <unistd.h>
#include <include/common.h>
#include <deps/rapidjson/include/rapidjson/document.h>
#include <deps/rapidjson/include/rapidjson/writer.h>
#include <deps/rapidjson/include/rapidjson/stringbuffer.h>

using namespace log;
using namespace config;
using namespace files;

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