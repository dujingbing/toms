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