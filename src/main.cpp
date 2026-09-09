#include <format>
#include <httplib.h>
#include <inja.hpp>
#include <json.hpp>
#include <spdlog/spdlog.h>
#include <string>

using json = nlohmann::json;

int main() {
  const unsigned int port{8080};
  const std::string host{"0.0.0.0"};

  httplib::Server svr;
  svr.set_mount_point("/public", "./public");
  svr.set_mount_point("/assets", "./assets");

  inja::Environment env;
  inja::Template home = env.parse_template("./templates/index.html");
  inja::Template projects = env.parse_template("./templates/projects.html");
  inja::Template blog = env.parse_template("./templates/blog.html");
  inja::Template contact = env.parse_template("./templates/contact.html");

  auto render = [&env](inja::Template &file, const json &data,
                       httplib::Response &res) {
    std::string result = env.render(file, data);
    res.set_content(result, "text/html");
  };

  svr.Get("/", [&](const httplib::Request &req, httplib::Response &res) {
    json data;
    data["title"] = "Home";
    render(home, data, res);
  });

  svr.Get("/blog", [&](const httplib::Request &req, httplib::Response &res) {
    json data;
    data["title"] = "Home";
    render(blog, data, res);
  });

  svr.Get("/contact", [&](const httplib::Request &req, httplib::Response &res) {
    json data;
    data["title"] = "Home";
    render(contact, data, res);
  });

  svr.Get("/projects",
          [&](const httplib::Request &req, httplib::Response &res) {
            json data;
            data["title"] = "Home";
            render(projects, data, res);
          });

  std::string message{std::format("listening to http://{}:{}", host, port)};
  spdlog::info(message);
  svr.listen(host, port);
}
