#include <inja.hpp>
#include <json.hpp>
#include <memory>
#include <server.hpp>

using json = nlohmann::json;

void setup_server(httplib::Server &svr) {
  svr.set_mount_point("/public", "./public");
  svr.set_mount_point("/assets", "./assets");

  auto env = std::make_shared<inja::Environment>();
  auto home = std::make_shared<inja::Template>(env->parse_template("./templates/index.html"));
  auto projects = std::make_shared<inja::Template>(env->parse_template("./templates/projects.html"));
  auto blog = std::make_shared<inja::Template>(env->parse_template("./templates/blog.html"));
  auto contact = std::make_shared<inja::Template>(env->parse_template("./templates/contact.html"));

  auto render = [env](inja::Template &file, const json &data,
                      httplib::Response &res) {
    std::string result = env->render(file, data);
    res.set_content(result, "text/html");
  };

  svr.Get("/", [render, home](const httplib::Request &, httplib::Response &res) {
    json data;
    data["title"] = "Home";
    render(*home, data, res);
  });

  svr.Get("/blog", [render, blog](const httplib::Request &, httplib::Response &res) {
    json data;
    data["title"] = "Home";
    render(*blog, data, res);
  });

  svr.Get("/contact",
          [render, contact](const httplib::Request &, httplib::Response &res) {
            json data;
            data["title"] = "Home";
            render(*contact, data, res);
          });

  svr.Get("/projects",
          [render, projects](const httplib::Request &, httplib::Response &res) {
            json data;
            data["title"] = "Home";
            render(*projects, data, res);
          });
}