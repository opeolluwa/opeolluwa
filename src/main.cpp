#include <format>
#include <server.hpp>
#include <spdlog/spdlog.h>
#include <string>

int main() {
  const unsigned int port{8080};
  const std::string host{"0.0.0.0"};

  httplib::Server svr;
  setup_server(svr);

  std::string message{std::format("listening to http://{}:{}", host, port)};
  spdlog::info(message);
  svr.listen(host, port);
}