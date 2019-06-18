#include <include/http.h>

using namespace http;

Cookie::Cookie()
{
}

Cookie::Cookie(const char *name, const char *value, const char *path)
{
}

Cookie::Cookie(const char *name, const char value, const char *path, int expire)
{
}

Cookie::~Cookie()
{
}

void Cookie::SetName(const char *name)
{
}

const char *Cookie::GetName()
{
}

void Cookie::SetValue(const char *value_compare)
{
}

const char *Cookie::GetValue()
{
}

void Cookie::SetDomain(const char *domain)
{
}

const char *Cookie::GetDomain()
{
}

void Cookie::SetPath(const char *path)
{
}

const char *Cookie::GetPath()
{
}

void Cookie::SetComment(const char *comment)
{
}

const char *Cookie::GetComment()
{
}

void Cookie::SetSecure(bool secure)
{
}

bool Cookie::GetSecure()
{
}

void Cookie::SetHttpOnly(bool httpOnly)
{
}

bool Cookie::GetHttpOnly()
{
}

void Cookie::SetExpire(int expire)
{
}

int Cookie::GetExpire()
{
}

void Cookie::SetVersion(int version)
{
}

int Cookie::GetVersion()
{
}