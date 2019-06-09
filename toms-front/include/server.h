#include <include/http.h>

namespace server
{
class HttpServer;
class ProtoServer;

class HttpServer
{
public:
    HttpServer();
    HttpServer(int port);
    ~HttpServer();

    bool listen();
    bool listen(int port);
};

class ProtoServer
{
public:
    ProtoServer();
    ProtoServer(int port);
    ~ProtoServer();

    bool listen();
    bool listen(int port);
};

} // namespace server