#include <include/server.h>

int main(int argc, char *argv[])
{
    //parameter should be the path of 'config.json'
    if (argc != 2)
    {
        printf("Toms-front server start error, lacking the configuration file path in parameters.");
        exit(1);
    }
    const char *configPath = argv[1];
    if (!files::FileUtils::exist(configPath))
    {
        printf("Toms-front server start error, configuration file does not exist, file '%s'.", configPath);
        exit(1);
    }

    config::Config *config = new config::Config();
    if (config->initialize(configPath))
    {
        printf("Toms-front server start error, configuration initialized failed, file '%s'.", configPath);
        exit(1);
    }
    log::Log::initialize(config->GetLogConfig());

    server::HttpServer *httpServer = new server::HttpServer(config->GetHttpServerConfig());
    httpServer->Listen();
}