#include <chrono>
#include <server.hpp>
#include <thread>

#include <gtest/gtest.h>
#include <httplib.h>

class ServerTest : public ::testing::Test {
protected:
  httplib::Server svr;
  std::thread server_thread;
  int port = 0;

  void SetUp() override {
    setup_server(svr);
    port = svr.bind_to_any_port("127.0.0.1");
    ASSERT_GT(port, 0) << "Failed to bind server to an ephemeral port";
    server_thread = std::thread([this]() { svr.listen_after_bind(); });
  }

  void TearDown() override {
    svr.stop();
    if (server_thread.joinable()) {
      server_thread.join();
    }
  }

  int get_status(const std::string &path) {
    httplib::Client client("127.0.0.1", port);
    return client.Get(path)->status;
  }
};

TEST_F(ServerTest, HomePage) {
  httplib::Client client("127.0.0.1", port);
  auto res = client.Get("/");
  ASSERT_TRUE(res) << "Request to / failed";
  EXPECT_EQ(res->status, 200);
  EXPECT_EQ(res->get_header_value("Content-Type"), "text/html");
}

TEST_F(ServerTest, BlogPage) {
  httplib::Client client("127.0.0.1", port);
  auto res = client.Get("/blog");
  ASSERT_TRUE(res) << "Request to /blog failed";
  EXPECT_EQ(res->status, 200);
  EXPECT_EQ(res->get_header_value("Content-Type"), "text/html");
}

TEST_F(ServerTest, ContactPage) {
  httplib::Client client("127.0.0.1", port);
  auto res = client.Get("/contact");
  ASSERT_TRUE(res) << "Request to /contact failed";
  EXPECT_EQ(res->status, 200);
  EXPECT_EQ(res->get_header_value("Content-Type"), "text/html");
}

TEST_F(ServerTest, ProjectsPage) {
  httplib::Client client("127.0.0.1", port);
  auto res = client.Get("/projects");
  ASSERT_TRUE(res) << "Request to /projects failed";
  EXPECT_EQ(res->status, 200);
  EXPECT_EQ(res->get_header_value("Content-Type"), "text/html");
}

TEST_F(ServerTest, UnknownRouteReturns404) {
  httplib::Client client("127.0.0.1", port);
  auto res = client.Get("/does-not-exist");
  ASSERT_TRUE(res) << "Request to /does-not-exist failed";
  EXPECT_EQ(res->status, 404);
}