// index.cpp
#include "mongoose.h"
#include <fstream>
#include <string>
#include <ctime>

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

// Função utilitária para pegar data/hora atual
std::string get_current_time() {
  time_t now = time(0);
  char buf[80];
  struct tm tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
  return buf;
}

// Lida com requisições
static void handle_request(struct mg_connection *nc, int ev, void *ev_data) {
  if (ev == MG_EV_HTTP_REQUEST) {
    struct http_message *hm = (struct http_message *) ev_data;

    // Endpoint para receber mensagens via POST
    if (mg_vcmp(&hm->uri, "/mensagem") == 0 && hm->method.p[0] == 'P') {
      char msg[500];
      mg_get_http_var(&hm->body, "mensagem", msg, sizeof(msg));

      // Salva a mensagem com timestamp
      std::ofstream outfile("mensagens.txt", std::ios::app);
      outfile << "[" << get_current_time() << "] " << msg << "\n";
      outfile.close();

      // Redireciona de volta
      mg_http_send_redirect(nc, 302, mg_mk_str("/index.html"), mg_mk_str(NULL));
    } else {
      // Serve arquivos estáticos (HTML, JS, CSS)
      mg_serve_http(nc, hm, s_http_server_opts);
    }
  }
}

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *nc;

  mg_mgr_init(&mgr, NULL);
  printf("Servidor rodando em http://localhost:%s\n", s_http_port);

  nc = mg_bind(&mgr, s_http_port, handle_request);
  if (nc == NULL) {
    printf("Erro ao iniciar servidor.\n");
    return 1;
  }

  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.document_root = ".";  // Serve a partir do diretório atual
  s_http_server_opts.enable_directory_listing = "no";

  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }

  mg_mgr_free(&mgr);
  return 0;
}
