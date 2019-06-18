#include <unistd.h>
#include <include/common.h>
#include <deps/rapidjson/include/rapidjson/document.h>
#include <deps/rapidjson/include/rapidjson/writer.h>
#include <deps/rapidjson/include/rapidjson/stringbuffer.h>

using namespace log;
using namespace config;
using namespace files;
using namespace rapidjson;

Config::Config()
{
}

Config::~Config()
{
}

bool Config::initialize(const char *configFile)
{
    //read configuration.
    char *config = FileUtils::Read(configFile);
    if (config == nullptr)
    {
        return false;
    }

    Document document;
    document.Parse(config);
    if (document.HasParseError())
    {
        free(config);
        printf("Toms-front server config parse error, detail '%s'.", GetParseErrorFunc(document.GetParseError()));
        return false;
    }
}