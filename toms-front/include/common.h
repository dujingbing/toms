#include <stdio.h>
#include <stdlib.h>

namespace config
{
class Config;
class HttpServerConfig;
class ProtoServerConfig;
class LogConfig;
class Constant;

class Config
{
private:
    HttpServerConfig *http;
    ProtoServerConfig *proto;
    LogConfig *log;

public:
    Config();
    ~Config();

    bool initialize(const char *configFile);
    HttpServerConfig *GetHttpServerConfig();
    ProtoServerConfig *GetProtoServerConfig();
    LogConfig *GetLogConfig();

    static const char *HTTTP_SERVER_KEY;
    static const char *PROTO_SERVER_KEY;
    static const char *LOG_KEY;
};
const char *Config::HTTTP_SERVER_KEY = "httpServer";
const char *Config::PROTO_SERVER_KEY = "protoServer";
const char *Config::LOG_KEY = "log";

class HttpServerConfig
{
private:
    int port;
    int maxConnectionSize;

public:
    HttpServerConfig();
    ~HttpServerConfig();

    void SetPort(int port);
    int GetPort();

    void SetMaxConnectionSize(int size);
    int GetMaxConnectionSize();

    static const char *PORT_KEY;
    static const char *MAX_CONNECTION_SIZE_KEY;
};
const char *HttpServerConfig::PORT_KEY = "port";
const char *HttpServerConfig::MAX_CONNECTION_SIZE_KEY = "maxConnectionSize";

class ProtoServerConfig
{
private:
    int port;

public:
    ProtoServerConfig();
    ~ProtoServerConfig();

    void SetPort(int port);
    int GetPort();

    static const char *PORT_KEY;
};
const char *ProtoServerConfig::PORT_KEY = "port";

class LogConfig
{
private:
    const char *home;
    //MB
    int maxFileSize;

public:
    LogConfig();
    ~LogConfig();

    void SetHome(const char *home);
    const char *GetHome();

    void SetMaxFileSize(int size);
    int GetMaxFileSize();

    static const char *HOME_KEY;
    static const char *MAX_FILE_SIZE_KEY;
};
const char *LogConfig::HOME_KEY = "port";
const char *LogConfig::MAX_FILE_SIZE_KEY = "maxConnectionSize";

}; // namespace config

namespace log
{
class Log;
class Constant;

class Log
{
private:
public:
    static bool initialize(config::LogConfig *config);

    static void Info(const char *file, const char *message, ...);

    static void Debug(const char *file, const char *message, ...);

    static void Warn(const char *file, const char *message, ...);

    static void Error(const char *file, const char *message, ...);
};

class Constant
{
public:
    static const char *SERVER_LOG;

    static const char *ROUTE_LOG;

    static const char *CONFIG_LOG;
};

const char *Constant::SERVER_LOG = "server.log";
const char *Constant::ROUTE_LOG = "route.log";
const char *Constant::CONFIG_LOG = "config.log";
} // namespace log

namespace files
{
class FileUtils;

class FileUtils
{
public:
    static bool Exist(const char *file);

    static char *Read(const char *file);
};
} // namespace files