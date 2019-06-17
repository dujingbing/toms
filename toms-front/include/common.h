#include <stdio.h>
#include <stdlib.h>

namespace config
{
class Config;
class ServerConfig;
class LogConfig;
class Constant;

class Config
{
private:
    const char *workDir;

    ServerConfig *server;
    LogConfig *log;

public:
    Config();
    ~Config();

    void initialize();
    ServerConfig *GetServerConfig();
    LogConfig *GetLogConfig();
};

class ServerConfig
{
private:
    int port;
    int maxConnectionSize;

public:
    ServerConfig();
    ~ServerConfig();

    void SetPort();
    int GetPort();

    void SetMaxConnectionSize(int size);
    int GetMaxConnectionSize();
};

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
};

class Constant
{
public:
    static const char *CONFIG_FILE_NAME;
};
const char *Constant::CONFIG_FILE_NAME = "config/config.json";

}; // namespace config

namespace log
{
class Log;
class Constant;

class Log
{
private:
public:
    static void initialize(config::LogConfig *config);

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