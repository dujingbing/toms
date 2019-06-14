#include <include/server.h>

using namespace server;
using namespace http;
using namespace log;

HttpServer::HttpServer()
{
    setting.on_message_begin = this->OnMessageBegin;
    setting.on_url = this->OnUrl;
    setting.on_status = this->OnStatus;
    setting.on_header_field = this->OnHeaderField;
    setting.on_header_value = this->OnHeaderValue;
    setting.on_headers_complete = this->OnHeadersComplete;
    setting.on_body = this->OnBody;
    setting.on_message_complete = this->OnMessageComplete;
}

HttpServer::~HttpServer()
{
}

void HttpServer::OnConnected(uv_stream_t *server, int status)
{
    if (status != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server on connected error, detail %s.", uv_err_name(status));
        exit(1);
    }

    Request *request = new Request();
    int tcp = uv_tcp_init(loop, request->tcp);
    if (tcp != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server on connected error, detail %s.", uv_err_name(tcp));
        exit(1);
    }
    http_parser_init(request->parser, HTTP_REQUEST);

    request->parser->data = request;
    request->tcp->data = request;
    int accept = uv_accept(server, (uv_stream_t *)request->tcp);
    if (accept != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server on connected error, detail %s.", uv_err_name(accept));
        exit(1);
    }

    uv_read_start((uv_stream_t *)request->tcp, this->AllocCallback, this->OnRead);
}

void HttpServer::AllocCallback(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf)
{
    *buf = uv_buf_init((char *)malloc(suggested_size), suggested_size);
}

void HttpServer::OnRead(uv_stream_t *tcp, ssize_t nread, const uv_buf_t *buf)
{
}

int HttpServer::OnMessageBegin(http_parser *parser)
{
}

int HttpServer::OnUrl(http_parser *parser, const char *at, size_t length)
{
}

int HttpServer::OnStatus(http_parser *parser, const char *at, size_t length)
{
}

int HttpServer::OnHeaderField(http_parser *parser, const char *at, size_t length)
{
}

int HttpServer::OnHeaderValue(http_parser *parser, const char *at, size_t length)
{
}

int HttpServer::OnHeadersComplete(http_parser *parser)
{
}

int HttpServer::OnBody(http_parser *parser, const char *at, size_t length)
{
}

int HttpServer::OnMessageComplete(http_parser *parser)
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
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server initialized error, server port(%d) is invalid.", port);
        exit(1);
    }

    loop = uv_default_loop();

    uv_tcp_t server;
    int tcp_init = uv_tcp_init(loop, &server);
    if (tcp_init != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server initialized error, detail %s.", uv_err_name(tcp_init));
        exit(1);
    }

    sockaddr_in address;
    int ip4_addr = uv_ip4_addr("127.0.0.1", port, &address);
    if (ip4_addr != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server initialized error, detail %s.", uv_err_name(ip4_addr));
        exit(1);
    }

    int tcp_bind = uv_tcp_bind(&server, (const struct sockaddr *)&address, 0);
    if (tcp_bind != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server initialized error, detail %s.", uv_err_name(tcp_bind));
        exit(1);
    }

    int listen = uv_listen((uv_stream_t *)&server, MAX_CONNECT_SIZE, this->OnConnected);
    if (listen != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server initialized error, detail %s.", uv_err_name(listen));
        exit(1);
    }

    Log::Info(log::Constant::SERVER_LOG, "Toms-front server start on port '%d'.", port);

    int run = uv_run(loop, UV_RUN_DEFAULT);
    if (run != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, detail %s.", run);
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