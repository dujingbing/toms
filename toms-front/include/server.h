#include <include/http.h>
#include <include/common.h>

namespace server
{
class HttpServer;
class ProtoServer;

class HttpServer
{
private:
    static const int DEFAULT_PORT = 6666;

    static const int MAX_CONNECT_SIZE = 10000;

    http_parser_settings setting;

    void OnConnected(uv_stream_t *server, int status);

    void AllocCallback(uv_handle_t * handle, size_t suggested_size, uv_buf_t* buf);

    void OnRead(uv_stream_t* tcp, ssize_t nread, const uv_buf_t * buf);

    uv_loop_t *loop;

public:
    HttpServer();
    HttpServer(int port);
    ~HttpServer();

    bool Listen();
    bool Listen(int port);
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