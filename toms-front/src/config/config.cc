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

    //validate configuration.
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
    rapidjson::Value &httpPort = httpServer[HttpServerConfig::PORT_KEY];
    if (!httpPort.IsInt())
    {
        free(config);
        printf("Toms-front server config parse error, 'port' in the 'httpServer' configuration is not a int value.");
        return false;
    }
    if (!httpServer.HasMember(HttpServerConfig::MAX_CONNECTION_SIZE_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'maxConnectionSize' in the 'httpServer' configuration.");
        return false;
    }
    rapidjson::Value &httpMaxConnectionSize = httpServer[HttpServerConfig::MAX_CONNECTION_SIZE_KEY];
    if (!httpMaxConnectionSize.IsString())
    {
        free(config);
        printf("Toms-front server config parse error, 'maxConnectionSize' in the 'httpServer' configuration is not a string value.");
        return false;
    }

    rapidjson::Value &protoServer = document[Config::PROTO_SERVER_KEY];
    if (!protoServer.HasMember(ProtoServerConfig::PORT_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'port' in the 'protoServer' configuration.");
        return false;
    }
    rapidjson::Value &protoServerPort = protoServer[ProtoServerConfig::PORT_KEY];
    if (!protoServerPort.IsInt())
    {
        free(config);
        printf("Toms-front server config parse error, 'port' in the 'protoServer' configuration is not a int value.");
        return false;
    }

    rapidjson::Value &log = document[Config::LOG_KEY];
    if (!log.HasMember(LogConfig::HOME_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'home' in the 'log' configuration.");
        return false;
    }
    rapidjson::Value &logHome = protoServer[LogConfig::HOME_KEY];
    if (!logHome.IsString())
    {
        free(config);
        printf("Toms-front server config parse error, 'home' in the 'log' configuration is not a string value.");
        return false;
    }
    if (!log.HasMember(LogConfig::MAX_FILE_SIZE_KEY))
    {
        free(config);
        printf("Toms-front server config parse error, no 'maxConnectionSize' in the 'log' configuration.");
        return false;
    }
    rapidjson::Value &logMaxFileSize = protoServer[LogConfig::MAX_FILE_SIZE_KEY];
    if (!logMaxFileSize.IsInt64())
    {
        free(config);
        printf("Toms-front server config parse error, 'maxConnectionSize' in the 'log' configuration is not a string value.");
        return false;
    }

    //initialize http server configuration.
    HttpServerConfig *httpServerConfig = new HttpServerConfig();
    httpServerConfig->SetPort(httpPort.GetInt());
    httpServerConfig->SetMaxConnectionSize(httpMaxConnectionSize.GetInt());
    this->http = httpServerConfig;

    ProtoServerConfig *protoServerConfig = new ProtoServerConfig();
    protoServerConfig->SetPort(protoServerPort.GetInt());
    this->proto = protoServerConfig;

    LogConfig *logConfig = new LogConfig();
    logConfig->SetHome(logHome.GetString());
    logConfig->SetMaxFileSize(logMaxFileSize.GetInt());
    this->log = logConfig;

    return true;
}