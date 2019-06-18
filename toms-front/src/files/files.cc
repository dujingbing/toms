#include <unistd.h>
#include <include/common.h>

using namespace log;
using namespace config;
using namespace files;

bool FileUtils::exist(const char *path)
{
    if (path == nullptr)
    {
        return false;
    }
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return false;
    }
    else
    {
        fclose(file);
        return true;
    }
}