#include <include/server.h>

using namespace server;
using namespace http;
using namespace log;

HttpServer::HttpServer()
{
    cb = new HttpCallback();
    setting.on_message_begin = cb->OnMessageBegin;
    setting.on_url = cb->OnUrl;
    setting.on_status = cb->OnStatus;
    setting.on_header_field = cb->OnHeaderField;
    setting.on_header_value = cb->OnHeaderValue;
    setting.on_headers_complete = cb->OnHeadersComplete;
    setting.on_body = cb->OnBody;
    setting.on_message_complete = cb->OnMessageComplete;
}

HttpServer::~HttpServer()
{
    delete cb;
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

void HttpServer::OnClose(uv_handle_t *handle)
{
    Request *request = (Request *)handle->data;
    delete request;
}

void HttpServer::OnRead(uv_stream_t *tcp, ssize_t nread, const uv_buf_t *buf)
{
    ssize_t parsed;
    Request *request = (Request *)tcp->data;
    if (nread >= 0)
    {
        parsed = (ssize_t)http_parser_execute(
            request->parser, &setting, buf->base, nread);
        if (request->parser->upgrade)
        {
            Log::Error(log::Constant::SERVER_LOG, "Toms-front server on read error, cannot handle http upgrade.");
            uv_close((uv_handle_t *)request->tcp, this->OnClose);
        }
        else if (parsed < nread)
        {
            Log::Error(log::Constant::SERVER_LOG, "Toms-front server on read error, arse error.");
            uv_close((uv_handle_t *)request->tcp, this->OnClose);
        }
    }
    else
    {
        if (nread != UV_EOF)
        {
            Log::Error(log::Constant::SERVER_LOG, "Toms-front server on read error, nread is not to 'EOF'.");
        }
        uv_close((uv_handle_t *)request->tcp, this->OnClose);
    }
    free(buf->base);
}

bool HttpServer::Listen()
{
    Listen(DEFAULT_PORT);
}

bool HttpServer::Listen(int port)
{
    if (port < 1024 || port > 49150)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, server port(%d) is invalid.", port);
        exit(1);
    }

    loop = uv_default_loop();

    uv_tcp_t server;
    int tcp_init = uv_tcp_init(loop, &server);
    if (tcp_init != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, detail %s.", uv_err_name(tcp_init));
        exit(1);
    }
    cb->SetLoop(loop);

    sockaddr_in address;
    int ip4_addr = uv_ip4_addr("127.0.0.1", port, &address);
    if (ip4_addr != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, detail %s.", uv_err_name(ip4_addr));
        exit(1);
    }

    int tcp_bind = uv_tcp_bind(&server, (const struct sockaddr *)&address, 0);
    if (tcp_bind != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, detail %s.", uv_err_name(tcp_bind));
        exit(1);
    }

    int listen = uv_listen((uv_stream_t *)&server, MAX_CONNECT_SIZE, this->OnConnected);
    if (listen != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, detail %s.", uv_err_name(listen));
        exit(1);
    }

    Log::Info(log::Constant::SERVER_LOG, "Toms-front server start on port '%d'.", port);

    int run = uv_run(loop, UV_RUN_DEFAULT);
    if (run != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server start error, detail %s.", uv_err_name(run));
    }
}

HttpCallback::HttpCallback()
{
    scb = new ServerCallback();
}

HttpCallback::~HttpCallback()
{
    delete scb;
}

void HttpCallback::SetLoop(uv_loop_t *loop)
{
}

int HttpCallback::OnMessageBegin(http_parser *parser)
{
    return 0;
}

int HttpCallback::OnUrl(http_parser *parser, const char *url, size_t length)
{
    Request *request = (Request *)parser->data;
    struct http_parser_url parser_url;
    int result = http_parser_parse_url(url, length, 0, &parser_url);
    if (result)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server on url parsing error, url %s.", url);
        return -1;
    }
    else
    {
        if ((parser_url.field_set & (1 << UF_PATH)))
        {
            const char *data = url + parser_url.field_data[UF_PATH].off;
            request->SetURL(url);
        }
        else
        {
            Log::Error(log::Constant::SERVER_LOG, "Toms-front server on url parsing error, url %s.", url);
            return -1;
        }
    }
    return 0;
}

int HttpCallback::OnStatus(http_parser *parser, const char *status, size_t length)
{
    Request *request = (Request *)parser->data;
    request->SetStatus(status);
    return 0;
}

int HttpCallback::OnHeaderField(http_parser *parser, const char *filed, size_t length)
{
    Request *request = (Request *)parser->data;
    request->SetHeaderField(filed);
    return 0;
}

int HttpCallback::OnHeaderValue(http_parser *parser, const char *value, size_t length)
{
    Request *request = (Request *)parser->data;
    request->SetHeaderField(value);
    return 0;
}

int HttpCallback::OnHeadersComplete(http_parser *parser)
{
    Request *request = (Request *)parser->data;
    request->SetHeader(request->GetHeaderField(), request->GetHeaderValue());
    request->ClearHeader();
    return 0;
}

int HttpCallback::OnBody(http_parser *parser, const char *body, size_t length)
{
    Request *request = (Request *)parser->data;
    request->SetContent(body);
    return 0;
}

int HttpCallback::OnMessageComplete(http_parser *parser)
{
    Request *request = (Request *)parser->data;
    int status = uv_queue_work(loop, &request->work, scb->Work, scb->AfterWork);
    if (status != 0)
    {
        Log::Error(log::Constant::SERVER_LOG, "Toms-front server on message complete error, detail %s.", uv_err_name(status));
    }
    return 0;
}

ServerCallback::ServerCallback()
{
}
ServerCallback::~ServerCallback()
{
}

void ServerCallback::Work(uv_work_t *work)
{
}

void ServerCallback::AfterWork(uv_work_t *work)
{
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