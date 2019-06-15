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

Response::Response()
{
}

Response::~Response()
{
}

void Response::AddCookie(Cookie &cookie)
{
}

void Response::AddHeader(const char *name, const char *value)
{
}

void Response::Send(int status)
{
}

void Response::Send(int status, const char *message)
{
}

void Response::SetStatus(int status)
{
}

void Response::SendRedirect(const char *location)
{
}

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