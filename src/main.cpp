#include "spdlog/spdlog.h"
#include <format>
#include <string.h>
#include <httplib.h>

int main() {
  const unsigned int port{8080};
  const std::string host{"0.0.0.0"};

  httplib::Server svr;
  svr.Get("/", [](const httplib::Request &, httplib::Response &res) {
    res.set_content("Hello, World!", "text/plain");
  });

  std::string message{std::format("listening to http://{}:{}", host, port)};
  spdlog::info(message);
  svr.listen(host, port);
}
