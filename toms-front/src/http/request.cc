#include <include/http.h>

using namespace http;

Request::Request()
{
}

Request::~Request()
{
}

void Request::SetURI(const char *uri)
{
}

const char *Request::GetUri()
{
}

void Request::SetURL(const char *url)
{
}

const char *Request::GetURL()
{
}

void Request::SetIP(const char *ip)
{
}

const char *Request::GetIP()
{
}

void Request::SetPort(int port)
{
}

int Request::GetPort()
{
}

void Request::SetContent(const char *content)
{
}

const char *Request::GetContent()
{
}

void Request::SetContentType(const char *contentType)
{
}

const char *Request::GetContentType()
{
}

int Request::GetContentLength()
{
}

void Request::SetHeaderField(const char *field)
{
}

const char *Request::GetHeaderField()
{
}

void Request::SetHeaderValue(const char *value)
{
}

const char *Request::GetHeaderValue()
{
}

void Request::ClearHeader()
{
}

void Request::SetHeader(const char *name, const char *value)
{
}

const char *Request::GetHeader(const char *name)
{
}

void Request::SetCookie(Cookie &cookie)
{
}

const char *Request::GetCookieValue(const char *name)
{
}

Cookie &Request::GetCookie(const char *name)
{
}

void Request::SetParameter(const char *name, const char *value)
{
}

const char *Request::GetParameterValue(const char *name)
{
}

std::vector<const char *> &Request::GetParameterNames()
{
}