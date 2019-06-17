#include <stdio.h>
#include <stdlib.h>

namespace config
{
class Config;
class ServerConfig;
class LogConfig;

class Config
{
private:
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

public:
    ServerConfig();
    ~ServerConfig();

    void SetPort();
    int GetPort();
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

} // namespace log