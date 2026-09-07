#include <httplib.h>
#include <iostream>

int main() {
    std::cout << "Ignition started";
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}
