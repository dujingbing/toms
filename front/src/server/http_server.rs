use actix_web::{web, App, HttpResponse, HttpServer, Responder};

fn index() -> impl Responder {
    HttpResponse::Ok().body("Hello world!");
}

/**
 * Server trait.
 *
 **/
pub trait FrontServer {
    fn start(&self);
}

pub struct FrontHttpServer {
    pub port: i64,
}

impl FrontServer for FrontHttpServer {
    fn start(&self) {
        HttpServer::new(|| App::new().route("/", web::get().to(index)))
            .bind("127.0.0.1:8080")
            .unwrap()
            .run()
            .unwrap();
    }
}
