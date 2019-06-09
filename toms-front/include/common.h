#include <stdio.h>
#include <stdlib.h>

namespace log
{
class Log;

class Log
{
public:
    /**
     * 
     * initialize 'Log' instance with current process directory.
    */
    Log();

    /**
     * 
     * initialize 'Log' instance with the specificed directory.
    */
    Log(const char *home);

    ~Log();

    void Info(const char *message, ...);

    void Info(const char *file, const char *message, ...);

    void Debug(const char *message, ...);

    void Debug(const char *file, const char *message, ...);

    void Warn(const char *message, ...);

    void Warn(const char *file, const char *message, ...);

    void Error(const char *message, ...);

    void Error(const char *file, const char *message, ...);
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