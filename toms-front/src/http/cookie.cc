#include <include/http.h>

using namespace http;

Cookie::Cookie()
{
    name = nullptr;
    value = nullptr;
    domain = nullptr;
    path = nullptr;
    comment = nullptr;
    secure = false;
    httpOnly = false;
    expire = -1;
    version = -1;
}

Cookie::Cookie(const char *name, const char *value, const char *path)
{
    if (name != nullptr && name[0] != '\0')
    {
        char *tmp = new char[strlen(name) + 1];
        strcpy(tmp, name);
        this->name = tmp;
    }
    if (value != nullptr && value[0] != '\0')
    {
        char *tmp = new char[strlen(value) + 1];
        strcpy(tmp, value);
        this->value = tmp;
    }
    if (path != nullptr && path[0] != '\0')
    {
        char *tmp = new char[strlen(path) + 1];
        strcpy(tmp, path);
        this->path = tmp;
    }
}

Cookie::Cookie(const char *name, const char *value, const char *path, int expire)
{
    Cookie(name, value, path);
    this->expire = expire;
}

Cookie::~Cookie()
{
    delete[] name;
    delete[] value;
    delete[] domain;
    delete[] path;
    delete[] comment;
}

void Cookie::SetName(const char *name)
{
    if (name != nullptr && name[0] != '\0')
    {
        char *tmp = new char[strlen(name) + 1];
        strcpy(tmp, name);
        this->name = tmp;
    }
}

const char *Cookie::GetName()
{
    return name;
}

void Cookie::SetValue(const char *value)
{
    if (value != nullptr && value[0] != '\0')
    {
        char *tmp = new char[strlen(value) + 1];
        strcpy(tmp, value);
        this->value = tmp;
    }
}

const char *Cookie::GetValue()
{
    return value;
}

void Cookie::SetDomain(const char *domain)
{
    if (domain != nullptr && domain[0] != '\0')
    {
        char *tmp = new char[strlen(domain) + 1];
        strcpy(tmp, domain);
        this->domain = tmp;
    }
}

const char *Cookie::GetDomain()
{
    return domain;
}

void Cookie::SetPath(const char *path)
{
    if (path != nullptr && path[0] != '\0')
    {
        char *tmp = new char[strlen(path) + 1];
        strcpy(tmp, path);
        this->path = tmp;
    }
}

const char *Cookie::GetPath()
{
    return path;
}

void Cookie::SetComment(const char *comment)
{
    if (comment != nullptr && comment[0] != '\0')
    {
        char *tmp = new char[strlen(comment) + 1];
        strcpy(tmp, comment);
        this->comment = tmp;
    }
}

const char *Cookie::GetComment()
{
    return comment;
}

void Cookie::SetSecure(bool secure)
{
    this->secure = secure;
}

bool Cookie::GetSecure()
{
    return secure;
}

void Cookie::SetHttpOnly(bool httpOnly)
{
    this->httpOnly = httpOnly;
}

bool Cookie::GetHttpOnly()
{
    return httpOnly;
}

void Cookie::SetExpire(int expire)
{
    this->expire = expire;
}

int Cookie::GetExpire()
{
    return expire;
}

void Cookie::SetVersion(int version)
{
    this->version = version;
}

int Cookie::GetVersion()
{
    return version;
}