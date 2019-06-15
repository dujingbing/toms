#include <include/http.h>
#include <include/common.h>

namespace server
{
class HttpServer;
class HttpCallback;
class ProtoServer;

class HttpServer
{
private:
    static const int DEFAULT_PORT = 6666;

    static const int MAX_CONNECT_SIZE = 10000;

    uv_loop_t *loop;

    HttpCallback *cb;

    http_parser_settings setting;

    void OnConnected(uv_stream_t *server, int status);

    void AllocCallback(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);

    void OnRead(uv_stream_t *tcp, ssize_t nread, const uv_buf_t *buf);

public:
    HttpServer();
    ~HttpServer();

    bool Listen();
    bool Listen(int port);
};

class HttpCallback
{
public:
    HttpCallback();
    ~HttpCallback();

    int OnMessageBegin(http_parser *parser);

    int OnUrl(http_parser *parser, const char *at, size_t length);

    int OnStatus(http_parser *parser, const char *at, size_t length);

    int OnHeaderField(http_parser *parser, const char *at, size_t length);

    int OnHeaderValue(http_parser *parser, const char *at, size_t length);

    int OnHeadersComplete(http_parser *parser);

    int OnBody(http_parser *parser, const char *at, size_t length);

    int OnMessageComplete(http_parser *parser);
};

class ProtoServer
{
public:
    ProtoServer();
    ProtoServer(int port);
    ~ProtoServer();

    bool Listen();
    bool Listen(int port);
};

} // namespace server