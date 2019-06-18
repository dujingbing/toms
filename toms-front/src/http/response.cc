#include <include/http.h>

using namespace http;

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