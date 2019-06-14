#include <stdio.h>
#include <stdlib.h>

namespace log
{
class Log;

class Log
{
private:
    static const char *home;

public:
    static void initialize(const char *home);

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