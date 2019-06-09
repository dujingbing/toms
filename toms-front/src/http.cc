#include <include/http.h>

using namespace http;

HttpRequest::HttpRequest()
{
}

HttpRequest::~HttpRequest()
{
}

void HttpRequest::SetURI(const char *uri)
{
}

const char *HttpRequest::GetUri()
{
}

void HttpRequest::SetURL(const char *url)
{
}

const char *HttpRequest::GetURL()
{
}

void HttpRequest::SetIP(const char *ip)
{
}

const char *HttpRequest::GetIP()
{
}

void HttpRequest::SetPort(int port)
{
}

int HttpRequest::GetPort()
{
}

void HttpRequest::SetContent(const char *content)
{
}

const char *HttpRequest::GetContent()
{
}

void HttpRequest::SetContentType(const char *contentType)
{
}

const char *HttpRequest::GetContentType()
{
}

int HttpRequest::GetContentLength()
{
}

void HttpRequest::SetHeader(const char *name, const char *value)
{
}

const char *HttpRequest::GetHeader(const char *name)
{
}

void HttpRequest::SetCookie(Cookie &cookie)
{
}

const char *HttpRequest::GetCookieValue(const char *name)
{
}

Cookie &HttpRequest::GetCookie(const char *name)
{
}

void HttpRequest::SetParameter(const char *name, const char *value)
{
}

const char *HttpRequest::GetParameterValue(const char *name)
{
}

std::vector<const char *> &HttpRequest::GetParameterNames()
{
}