#include <include/common.h>

using namespace config;

ProtoServerConfig::ProtoServerConfig()
{
}

ProtoServerConfig::~ProtoServerConfig()
{
}

void ProtoServerConfig::SetPort(int port)
{
    this->port = port;
}

int ProtoServerConfig::GetPort()
{
    return port;
}