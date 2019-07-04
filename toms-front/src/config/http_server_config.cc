#include <include/common.h>

using namespace config;

HttpServerConfig::HttpServerConfig()
{
}

HttpServerConfig::~HttpServerConfig()
{
}

void HttpServerConfig::SetPort(int port)
{
    this->port = port;
}

int HttpServerConfig::GetPort()
{
    return port;
}

void HttpServerConfig::SetMaxConnectionSize(int size)
{
    this->maxConnectionSize = size;
}

int HttpServerConfig::GetMaxConnectionSize()
{
    return maxConnectionSize;
}