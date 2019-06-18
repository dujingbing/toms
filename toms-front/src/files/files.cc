#include <unistd.h>
#include <include/common.h>

using namespace log;
using namespace config;
using namespace files;

bool FileUtils::Exist(const char *path)
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

char *FileUtils::Read(const char *path)
{
    if (path == nullptr)
    {
        return nullptr;
    }
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return nullptr;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    if (size == 0)
    {
        fclose(file);
        return "";
    }

    char *result = (char *)malloc(sizeof(char) * size);
    if (result == NULL)
    {
        fclose(file);
        return nullptr;
    }
    int readSize = fread(result, 1, size, file);
    if (readSize != size)
    {
        free(result);
        fclose(file);
        return nullptr;
    }

    fclose(file);
    return result;
}