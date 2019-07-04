#include <include/http.h>

using namespace http;

Request::Request()
{
    uri = nullptr;
    url = nullptr;
    ip = nullptr;
    port = -1;
    contentLength = 0;
    contentType = nullptr;
    content = nullptr;
    status = nullptr;
    headerFiled = nullptr;
    headerValue = nullptr;
}

Request::~Request()
{
    delete[] uri;
    delete[] url;
    delete[] ip;
    delete[] content;
    delete[] status;
    delete[] headerFiled;
    delete[] headerValue;

    for (std::map<const char *, const char *>::iterator it = headers.begin(); it != headers.end(); it++)
    {
        delete[] it->first;
        delete[] it->second;
        headers.erase(it);
    }
    for (std::map<const char *, Cookie *>::iterator it = cookies.begin(); it != cookies.end(); it++)
    {
        delete[] it->first;
        delete it->second;
        cookies.erase(it);
    }
    for (std::map<const char *, const char *>::iterator it = parameters.begin(); it != parameters.end(); it++)
    {
        delete[] it->first;
        delete[] it->second;
        parameters.erase(it);
    }
}

void Request::SetURI(const char *uri)
{
    if (uri != nullptr)
    {
        char *tmp = new char[strlen(uri) + 1];
        strcpy(tmp, uri);
        this->uri = tmp;
    }
}

const char *Request::GetUri()
{
    return uri;
}

void Request::SetURL(const char *url)
{
    if (url != nullptr)
    {
        char *tmp = new char[strlen(url) + 1];
        strcpy(tmp, url);
        this->url = tmp;
    }
}

const char *Request::GetURL()
{
    return url;
}

void Request::SetIP(const char *ip)
{
    if (ip != nullptr)
    {
        char *tmp = new char[strlen(ip) + 1];
        strcpy(tmp, ip);
        this->ip = tmp;
    }
}

const char *Request::GetIP()
{
    return ip;
}

void Request::SetPort(int port)
{
    this->port = port;
}

int Request::GetPort()
{
    return port;
}

void Request::SetContent(const char *content)
{
    if (content != nullptr)
    {
        char *tmp = new char[strlen(content) + 1];
        strcpy(tmp, content);
        this->content = tmp;
    }
}

const char *Request::GetContent()
{
    return content;
}

void Request::SetContentType(const char *contentType)
{
    if (contentType != nullptr)
    {
        char *tmp = new char[strlen(contentType) + 1];
        strcpy(tmp, contentType);
        this->contentType = tmp;
    }
}

const char *Request::GetContentType()
{
    return contentType;
}

int Request::GetContentLength()
{
    if (content == nullptr)
    {
        return 0;
    }
    else
    {
        return strlen(content);
    }
}

void Request::SetHeaderField(const char *field)
{
    if (field != nullptr)
    {
        char *tmp = new char[strlen(field) + 1];
        strcpy(tmp, field);
        this->headerFiled = tmp;
    }
}

const char *Request::GetHeaderField()
{
    return headerFiled;
}

void Request::SetHeaderValue(const char *value)
{
    if (value != nullptr)
    {
        char *tmp = new char[strlen(value) + 1];
        strcpy(tmp, value);
        this->headerValue = tmp;
    }
}

const char *Request::GetHeaderValue()
{
    return headerValue;
}

void Request::ClearHeader()
{
    delete[] headerFiled;
    delete[] headerValue;
    headerFiled = nullptr;
    headerValue = nullptr;
}

void Request::SetHeader(const char *name, const char *value)
{
    if (name != nullptr && name[0] == '\0' && value != nullptr)
    {
        char *_name = new char[strlen(name) + 1];
        char *_value = new char[strlen(value) + 1];
        strcpy(_name, name);
        strcpy(_value, value);
        headers.insert(std::pair<const char *, const char *>(_name, _value));
    }
}

const char *Request::GetHeader(const char *name)
{
    if (name == nullptr || name[0] == '\0')
    {
        return nullptr;
    }
    if (headers.count(name) == 0)
    {
        return nullptr;
    }
    return headers[name];
}

void Request::SetCookie(Cookie &cookie)
{
    const char *name = cookie.GetName();
    if (name == nullptr || name[0] == '\0')
    {
        return;
    }
    Cookie *_cookie = new Cookie(name, cookie.GetValue(), cookie.GetPath(), cookie.GetExpire());
    _cookie->SetDomain(cookie.GetDomain());
    _cookie->SetComment(cookie.GetComment());
    _cookie->SetSecure(cookie.GetSecure());
    _cookie->SetHttpOnly(cookie.GetHttpOnly());
    _cookie->SetVersion(cookie.GetVersion());
    cookies.insert(std::pair<const char *, Cookie *>(name, _cookie));
}

const char *Request::GetCookieValue(const char *name)
{
    if (name == nullptr || name[0] == '\0')
    {
        return nullptr;
    }
    if (cookies.count(name) == 0)
    {
        return nullptr;
    }
    Cookie *cookie = cookies[name];
    return cookie->GetValue();
}

Cookie *Request::GetCookie(const char *name)
{
    if (name == nullptr || name[0] == '\0')
    {
        return nullptr;
    }
    if (cookies.count(name) == 0)
    {
        return nullptr;
    }
    return cookies[name];
}

void Request::SetParameter(const char *name, const char *value)
{
    if (name == nullptr || name[0] == '\0' || value == nullptr)
    {
        return;
    }
    char *_name = new char[strlen(name) + 1];
    char *_value = new char[strlen(value) + 1];
    strcpy(_name, name);
    strcpy(_value, value);
    parameters.insert(std::pair<const char *, const char *>(_name, _value));
}

const char *Request::GetParameterValue(const char *name)
{
    if (name == nullptr || name[0] == '\0')
    {
        return nullptr;
    }
    if (parameters.count(name) == 0)
    {
        return nullptr;
    }
    return parameters[name];
}

std::vector<const char *> *Request::GetParameterNames()
{
    if (parameters.size() == 0)
    {
        return nullptr;
    }
    std::vector<const char *> *names = new std::vector<const char *>();
    for (std::map<const char *, const char *>::iterator it = parameters.begin(); it != parameters.end(); it++)
    {
        names->push_back(it->first);
    }
    return names;
}

void Request::SetStatus(const char *status)
{
    if (status == nullptr)
    {
        return;
    }
    char *_status = new char[strlen(status) + 1];
    strcpy(_status, status);
    this->status = _status;
}

const char *Request::GetStatus()
{
    return status;
}