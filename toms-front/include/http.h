#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#include <deps/uv/include/uv.h>
#include <deps/http-parser/http_parser.h>

namespace http
{
class Request;
class Response;
class Cookie;
class Status;

class Request
{
private:
    const char *uri;
    const char *url;
    const char *ip;
    int port;
    int contentLength;
    int contentType;
    const char *content;
    const char *status;
    const char *headerFiled;
    const char *headerValue;
    std::map<const char *, const char *> headers;
    std::map<const char *, Cookie> cookies;
    std::map<const char *, const char *> parameters;

public:
    Request();
    ~Request();

    uv_tcp_t *tcp;
    http_parser *parser;
    uv_write_t *write;
    uv_work_t work;

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

    void SetHeaderField(const char *field);
    const char *GetHeaderField();
    void SetHeaderValue(const char *value);
    const char *GetHeaderValue();
    void ClearHeader();
    void SetHeader(const char *name, const char *value);
    const char *GetHeader(const char *name);

    void SetCookie(Cookie &cookie);
    const char *GetCookieValue(const char *name);
    Cookie &GetCookie(const char *name);

    void SetParameter(const char *name, const char *value);
    const char *GetParameterValue(const char *name);
    std::vector<const char *> &GetParameterNames();

    void SetStatus(const char *status);
    const char *GetStatus();
};

class Response
{
private:
    uv_write_t *write;
    int status;
    std::map<const char *, const char *> headers;
    std::map<const char *, Cookie> cookies;

public:
    Response();
    ~Response();

    void AddCookie(Cookie &cookie);

    void AddHeader(const char *name, const char *value);

    void Send(int status);

    void Send(int status, const char *message);

    void SetStatus(int status);

    void SendRedirect(const char *location);
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

    Cookie(const char *name, const char *value, const char *path, int expire);

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

class Status
{
public:
    /**
     * 
     * Status code (100) indicating the client can continue.
    */
    static const int SC_CONTINUE = 100;

    /**
     * 
     * Status code (101) indicating the server is switching protocols according to Upgrade header.
    */
    static const int SC_SWITCHING_PROTOCOLS = 101;

    /**
     * 
     * Status code (200) indicating the request succeeded normally.
    */
    static const int SC_OK = 200;

    /**
     * 
     * Status code (201) indicating the request succeeded and created a new resource on the server.
    */
    static const int SC_CREATED = 201;

    /**
     * 
     * Status code (202) indicating that a request was accepted for processing, but was not completed.
    */
    static const int SC_ACCEPTED = 202;

    /**
     * 
     * Status code (203) indicating that the meta information presented by the client did not originate from the server.
    */
    static const int SC_NON_AUTHORITATIVE_INFORMATION = 203;

    /**
     * 
     * Status code (204) indicating that the request succeeded but that there was no new information to return.
    */
    static const int SC_NO_CONTENT = 204;

    /**
     * 
     * Status code (205) indicating that the agent SHOULD reset the document view which caused the request to be sent.
    */
    static const int SC_RESET_CONTENT = 205;

    /**
     * 
     * Status code (206) indicating that the server has fulfilled the partial GET request for the resource.
    */
    static const int SC_PARTIAL_CONTENT = 206;

    /**
     * 
     * Status code (300) indicating that the requested resource corresponds to any one of a set of representations, each with its own specific location.
    */
    static const int SC_MULTIPLE_CHOICES = 300;

    /**
     * 
     * Status code (301) indicating that the resource has permanently moved to a new location, and that future references should use a new URI with their requests.
    */
    static const int SC_MOVED_PERMANENTLY = 301;

    /**
     * 
     * Status code (302) indicating that the resource has temporarily moved to another location, but that future references should still use the original URI to access the resource.
    */
    static const int SC_MOVED_TEMPORARILY = 302;

    /**
     * 
     * Status code (303) indicating that the response to the request can be found under a different URI.
    */
    static const int SC_SEE_OTHER = 303;

    /**
     * 
     * Status code (304) indicating that a conditional GET operation found that the resource was available and not modified.
    */
    static const int SC_NOT_MODIFIED = 304;

    /**
     * 
     * Status code (305) indicating that the requested resource MUST be accessed through the proxy given by the Location field.
    */
    static const int SC_USE_PROXY = 305;

    /**
     * 
     * Status code (307) indicating that the requested resource resides temporarily under a different URI.
    */
    static const int SC_TEMPORARY_REDIRECT = 307;

    /**
     * 
     *  Status code (400) indicating the request sent by the client was syntactically incorrect.
    */
    static const int SC_BAD_REQUEST = 400;

    /**
     * 
     *  Status code (401) indicating that the request requires HTTP authentication.
    */
    static const int SC_UNAUTHORIZED = 401;

    /**
     * 
     *  Status code (402) reserved for future use.
    */
    static const int SC_PAYMENT_REQUIRED = 402;

    /**
     * 
     *  Status code (403) indicating the server understood the request but refused to fulfill it.
    */
    static const int SC_FORBIDDEN = 403;

    /**
     * 
     *  Status code (404) indicating that the requested resource is not available.
    */
    static const int SC_NOT_FOUND = 404;

    /**
     * 
     *  Status code (405) indicating that the method specified in the Request-Line is not allowed for the resource identified by the Request-URI.
    */
    static const int SC_METHOD_NOT_ALLOWED = 405;

    /**
     * 
     *  Status code (406) indicating that the resource identified by the request is only capable of generating response entities which have content characteristics not acceptable according to the accept headers sent in the request.
    */
    static const int SC_NOT_ACCEPTABLE = 406;

    /**
     * 
     *  Status code (407) indicating that the client MUST first authenticate itself with the proxy.
    */
    static const int SC_PROXY_AUTHENTICATION_REQUIRED = 407;

    /**
     * 
     *  Status code (408) indicating that the client did not produce a request within the time that the server was prepared to wait.
    */
    static const int SC_REQUEST_TIMEOUT = 408;

    /**
     * 
     *  Status code (409) indicating that the request could not be completed due to a conflict with the current state of the resource.
    */
    static const int SC_CONFLICT = 409;

    /**
     * 
     *  Status code (410) indicating that the resource is no longer available at the server and no forwarding address is known.
    */
    static const int SC_GONE = 410;

    /**
     * 
     *  Status code (411) indicating that the request cannot be handled without a defined Content-Length.
    */
    static const int SC_LENGTH_REQUIRED = 411;

    /**
     * 
     *  Status code (412) indicating that the precondition given in one or more of the request-header fields evaluated to false when it was tested on the server.
    */
    static const int SC_PRECONDITION_FAILED = 412;

    /**
     * 
     *  Status code (413) indicating that the server is refusing to process the request because the request entity is larger than the server is willing or able to process.
    */
    static const int SC_REQUEST_ENTITY_TOO_LARGE = 413;

    /**
     * 
     *  Status code (414) indicating that the server is refusing to service the request because the Request-URI is longer than the server is willing to interpret.
    */
    static const int SC_REQUEST_URI_TOO_LONG = 414;

    /**
     * 
     *  Status code (415) indicating that the server is refusing to service the request because the entity of the request is in a format not supported by the requested resource for the requested method.
    */
    static const int SC_UNSUPPORTED_MEDIA_TYPE = 415;

    /**
     * 
     *  Status code (416) indicating that the server cannot serve the requested byte range.
    */
    static const int SC_REQUESTED_RANGE_NOT_SATISFIABLE = 416;

    /**
     * 
     *  Status code (417) indicating that the server could not meet the expectation given in the Expect request header.
    */
    static const int SC_EXPECTATION_FAILED = 417;

    /**
     * 
     *  Status code (500) indicating an error inside the HTTP server which prevented it from fulfilling the request.
    */
    static const int SC_INTERNAL_SERVER_ERROR = 500;

    /**
     * 
     *  Status code (501) indicating the HTTP server does not support the functionality needed to fulfill the request.
    */
    static const int SC_NOT_IMPLEMENTED = 501;

    /**
     * 
     *  Status code (502) indicating that the HTTP server received an invalid response from a server it consulted when acting as a proxy or gateway.
    */
    static const int SC_BAD_GATEWAY = 502;

    /**
     * 
     *  Status code (503) indicating that the HTTP server is temporarily overloaded, and unable to handle the request.
    */
    static const int SC_SERVICE_UNAVAILABLE = 503;

    /**
     * 
     *  Status code (504) indicating that the server did not receive a timely response from the upstream server while acting as a gateway or proxy.
    */
    static const int SC_GATEWAY_TIMEOUT = 504;

    /**
     * 
     *  Status code (505) indicating that the server does not support or refuses to support the HTTP protocol version that was used in the request message.
    */
    static const int SC_HTTP_VERSION_NOT_SUPPORTED = 505;
};

} // namespace http