#include <include/http.h>
#include <deps/uv/include/uv.h>
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

    static void OnConnected(uv_stream_t *server, int status);

    uv_loop_t *loop;

    log::Log *log;

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