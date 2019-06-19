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
    if (!document.HasMember(Config::HTTTP_SERVER_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'httpServer' configuration.");
        return false;
    }
    if (!document.HasMember(Config::PROTO_SERVER_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'protoServer' configuration.");
        return false;
    }
    if (!document.HasMember(Config::LOG_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'log' configuration.");
        return false;
    }

    rapidjson::Value &httpServer = document[Config::HTTTP_SERVER_KEY];
    if (!httpServer.HasMember(HttpServerConfig::PORT_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'port' in the 'httpServer' configuration.");
        return false;
    }
    if (!httpServer.HasMember(HttpServerConfig::MAX_CONNECTION_SIZE_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'maxConnectionSize' in the 'httpServer' configuration.");
        return false;
    }

    rapidjson::Value &protoServer = document[Config::PROTO_SERVER_KEY];
    if (!protoServer.HasMember(ProtoServerConfig::PORT_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'port' in the 'protoServer' configuration.");
        return false;
    }

    rapidjson::Value &log = document[Config::LOG_KEY];
    if (!httpServer.HasMember(LogConfig::HOME_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'home' in the 'log' configuration.");
        return false;
    }
    if (!httpServer.HasMember(LogConfig::MAX_FILE_SIZE_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'maxConnectionSize' in the 'log' configuration.");
        return false;
    }
}