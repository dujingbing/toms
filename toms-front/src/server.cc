#include <include/server.h>

using namespace server;

HttpServer::HttpServer()
{
}

HttpServer::HttpServer(int port)
{
}

HttpServer::~HttpServer()
{
}

void HttpServer::OnConnected(uv_stream_t *server, int status)
{
}

bool HttpServer::Listen()
{
    Listen(DEFAULT_PORT);
}

bool HttpServer::Listen(int port)
{
    if (port < 1024 || port > 49150)
    {
        fprintf(stderr, "Toms-front server initialized error, server port(%d) is invalid.\n", port);
        exit(1);
    }

    loop = uv_default_loop();

    uv_tcp_t server;
    int tcp_init = uv_tcp_init(loop, &server);
    if (tcp_init != 0)
    {
        fprintf(stderr, "%s: %s.\n", "Toms-front server initialized error, detail", uv_err_name(tcp_init));
        exit(1);
    }

    sockaddr_in address;
    int ip4_addr = uv_ip4_addr("127.0.0.1", port, &address);
    if (ip4_addr != 0)
    {
        fprintf(stderr, "%s: %s.\n", "Toms-front server initialized error, detail", uv_err_name(ip4_addr));
        exit(1);
    }

    int tcp_bind = uv_tcp_bind(&server, (const struct sockaddr *)&address, 0);
    if (tcp_bind != 0)
    {
        fprintf(stderr, "%s: %s.\n", "Toms-front server initialized error, detail", uv_err_name(tcp_bind));
        exit(1);
    }

    int listen = uv_listen((uv_stream_t *)&server, MAX_CONNECT_SIZE, OnConnected);
    if (listen != 0)
    {
        fprintf(stderr, "%s: %s.\n", "Toms-front server initialized error, detail", uv_err_name(listen));
        exit(1);
    }
}

ProtoServer::ProtoServer()
{
}

ProtoServer::ProtoServer(int port)
{
}

ProtoServer::~ProtoServer()
{
}

bool ProtoServer::Listen()
{
}

bool ProtoServer::Listen(int port)
{
}