#include <unistd.h>
#include <include/common.h>

using namespace log;

bool Log::initialize(config::LogConfig *config)
{
    if (config == nullptr)
    {
        return false;
    }
    if (!files::FileUtils::Exist(config->GetHome()))
    {
        return false;
    }

    if (config->GetMaxFileSize() > 512)
    {
        //max file size 512MB.
        config->SetMaxFileSize(512);
    }
    if (config->GetMaxFileSize() < 5)
    {
        //min file size 5MB.
        config->SetMaxFileSize(5);
    }
    if (config->GetMaxMessageSize() < 1024)
    {
        config->SetMaxMessageSize(1024);
    }
    Log::config = config;
    return true;
}

void Log::Info(const char *fileName, const char *message, ...)
{
    if (fileName == nullptr)
    {
        return;
    }

    if (Log::logFile.count(fileName) == 0)
    {
        //not exist.
        const char *home = Log::config->GetHome();
        int homeLen = strlen(home);
        char *logFilePath = new char[homeLen + strlen(fileName) + 1];
        if (home[homeLen - 1] == '/')
        {
            sprintf(logFilePath, "%s%s", home, fileName);
        }
        else
        {
            sprintf(logFilePath, "%s/%s", home, fileName);
        }

        FILE *logFile = fopen(logFilePath, "rw");
        delete[] logFilePath;
        if (logFile == NULL)
        {
            return;
        }
        Log::logFile.insert(std::pair<const char *, FILE *>(fileName, logFile));
    }
    FILE *logFile = Log::logFile[fileName];

    time_t timestamp = time(0);
    tm *now = localtime(&timestamp);

    char prefix[30];
    sprintf(prefix, "%d-%d-%d %d:%d:%d - INFO - ", now->tm_year, now->tm_mon, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    char input[Log::config->GetMaxMessageSize()];
    va_list args;
    va_start(args, message);
    vsprintf(input, message, args);
    va_end(args);

    char msg[strlen(prefix) + strlen(input) + 1];
    sprintf(msg, "%s/%s", prefix, input);
    fprintf(logFile, msg);
}

void Log::Debug(const char *fileName, const char *message, ...)
{
    if (fileName == nullptr)
    {
        return;
    }

    if (Log::logFile.count(fileName) == 0)
    {
        //not exist.
        const char *home = Log::config->GetHome();
        int homeLen = strlen(home);
        char *logFilePath = new char[homeLen + strlen(fileName) + 1];
        if (home[homeLen - 1] == '/')
        {
            sprintf(logFilePath, "%s%s", home, fileName);
        }
        else
        {
            sprintf(logFilePath, "%s/%s", home, fileName);
        }

        FILE *logFile = fopen(logFilePath, "rw");
        delete[] logFilePath;
        if (logFile == NULL)
        {
            return;
        }
        Log::logFile.insert(std::pair<const char *, FILE *>(fileName, logFile));
    }
    FILE *logFile = Log::logFile[fileName];

    time_t timestamp = time(0);
    tm *now = localtime(&timestamp);

    char prefix[30];
    sprintf(prefix, "%d-%d-%d %d:%d:%d - DEBUG - ", now->tm_year, now->tm_mon, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    char input[Log::config->GetMaxMessageSize()];
    va_list args;
    va_start(args, message);
    vsprintf(input, message, args);
    va_end(args);

    char msg[strlen(prefix) + strlen(input) + 1];
    sprintf(msg, "%s/%s", prefix, input);
    fprintf(logFile, msg);
}

void Log::Warn(const char *fileName, const char *message, ...)
{
    if (fileName == nullptr)
    {
        return;
    }

    if (Log::logFile.count(fileName) == 0)
    {
        //not exist.
        const char *home = Log::config->GetHome();
        int homeLen = strlen(home);
        char *logFilePath = new char[homeLen + strlen(fileName) + 1];
        if (home[homeLen - 1] == '/')
        {
            sprintf(logFilePath, "%s%s", home, fileName);
        }
        else
        {
            sprintf(logFilePath, "%s/%s", home, fileName);
        }

        FILE *logFile = fopen(logFilePath, "rw");
        delete[] logFilePath;
        if (logFile == NULL)
        {
            return;
        }
        Log::logFile.insert(std::pair<const char *, FILE *>(fileName, logFile));
    }
    FILE *logFile = Log::logFile[fileName];

    time_t timestamp = time(0);
    tm *now = localtime(&timestamp);

    char prefix[30];
    sprintf(prefix, "%d-%d-%d %d:%d:%d - WARN - ", now->tm_year, now->tm_mon, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    char input[Log::config->GetMaxMessageSize()];
    va_list args;
    va_start(args, message);
    vsprintf(input, message, args);
    va_end(args);

    char msg[strlen(prefix) + strlen(input) + 1];
    sprintf(msg, "%s/%s", prefix, input);
    fprintf(logFile, msg);
}

void Log::Error(const char *fileName, const char *message, ...)
{
    if (fileName == nullptr)
    {
        return;
    }

    if (Log::logFile.count(fileName) == 0)
    {
        //not exist.
        const char *home = Log::config->GetHome();
        int homeLen = strlen(home);
        char *logFilePath = new char[homeLen + strlen(fileName) + 1];
        if (home[homeLen - 1] == '/')
        {
            sprintf(logFilePath, "%s%s", home, fileName);
        }
        else
        {
            sprintf(logFilePath, "%s/%s", home, fileName);
        }

        FILE *logFile = fopen(logFilePath, "rw");
        delete[] logFilePath;
        if (logFile == NULL)
        {
            return;
        }
        Log::logFile.insert(std::pair<const char *, FILE *>(fileName, logFile));
    }
    FILE *logFile = Log::logFile[fileName];

    time_t timestamp = time(0);
    tm *now = localtime(&timestamp);

    char prefix[30];
    sprintf(prefix, "%d-%d-%d %d:%d:%d - ERROR - ", now->tm_year, now->tm_mon, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    char input[Log::config->GetMaxMessageSize()];
    va_list args;
    va_start(args, message);
    vsprintf(input, message, args);
    va_end(args);

    char msg[strlen(prefix) + strlen(input) + 1];
    sprintf(msg, "%s/%s", prefix, input);
    fprintf(logFile, msg);
}