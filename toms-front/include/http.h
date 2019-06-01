#include <map>
#include <vector>

namespace front
{
class HttpRequest;
class HttpResponse;
class Cookie;

class HttpRequest
{
private:
    const char *uri;
    const char *url;
    const char *ip;
    int port;
    int contentLength;
    int contentType;
    const char *content;
    std::map<const char *, const char *> headers;
    std::map<const char *, Cookie> cookies;

public:
    HttpRequest();
    ~HttpRequest();

    void SetURI(const char *uri);
    const char *GetUri();

    void SetURL(const char *url);
    const char *GetURL();

    void SetIP(const char *ip);
    const char *GetIP();

    void SetPort(int port);
    int GetPort();

    void SetContent(const char *content);
    const char *GetContent();

    void SetContentType(const char *contentType);
    const char *GetContentType();

    int GetContentLength();

    void SetHeader(const char *name, const char *value);
    const char *GetHeader(const char *name);

    void SetCookie(Cookie &cookie);
    const char *GetCookieValue(const char *name);
    Cookie GetCookie(const char *name);
};

class HttpResponse
{
};

class Cookie
{
private:
    const char *name;
    const char *value;
    const char *domain;
    const char *path;
    const char *comment;
    bool secure;
    bool httpOnly;
    int expire;
    int version;

public:
    Cookie();

    Cookie(const char *name, const char *value, const char *path);

    Cookie(const char *name, const char value, const char *path, int expire);

    ~Cookie();

    void SetName(const char *name);
    const char *GetName();

    void SetValue(const char *value_compare);
    const char *GetValue();

    void SetDomain(const char *domain);
    const char *GetDomain();

    void SetPath(const char *path);
    const char *GetPath();

    void SetComment(const char *comment);
    const char *GetComment();

    void SetSecure(bool secure);
    bool GetSecure();

    void SetHttpOnly(bool httpOnly);
    bool GetHttpOnly();

    void SetExpire(int expire);
    int GetExpire();

    void SetVersion(int version);
    int GetVersion();
};

} // namespace front