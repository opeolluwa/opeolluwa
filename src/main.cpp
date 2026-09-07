#include "spdlog/spdlog.h"
#include <format>
#include <httplib.h>
#include <string.h>

int main() {
  const unsigned int port{8080};
  const std::string host{"0.0.0.0"};

  httplib::Server svr;
  svr.set_mount_point("/public", "./public");
  svr.set_mount_point("/assets", "./assets");
  svr.set_mount_point("/", "./templates");

  svr.Get("/f", [](const httplib::Request &, httplib::Response &res) {
    res.set_content("Hello, World!", "text/html");
  });

  std::string message{std::format("listening to http://{}:{}", host, port)};
  spdlog::info(message);
  svr.listen(host, port);
}
