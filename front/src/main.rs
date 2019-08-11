mod server;
use server::FrontServer;
use server::FrontHttpServer;

fn main() {
    let http_server = FrontHttpServer { port: 8080 };
    println!("Server started, port {}.", http_server.port);
    http_server.start();
}
