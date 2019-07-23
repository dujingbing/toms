package server

import (
	hserver "./http"
	pserver "./proto"
)

type Server interface {
	Listen(port int)
}

type HttpServer struct {
	port int
}

func (HttpServer) Listen(port int) {
	hserver.Listen(port)
}

type ProtoServer struct {
	port int
}

func (ProtoServer) Listen(port int) {
	pserver.Listen(port)
}
