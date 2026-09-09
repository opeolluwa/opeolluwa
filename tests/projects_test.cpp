#include <projects.hpp>

#include <gtest/gtest.h>

TEST(ProjectTest, DefaultConstruction) {
  Project project;
  EXPECT_EQ(project.name, "");
  EXPECT_EQ(project.description, "");
  EXPECT_EQ(project.repository_url, "");
  EXPECT_TRUE(project.technologies.empty());
}

TEST(ProjectTest, AssignFields) {
  Project project;
  project.name = "Lunar";
  project.description = "help";
  project.repository_url = "https://github.com/opeolluwa/lunar";

  EXPECT_EQ(project.name, "Lunar");
  EXPECT_EQ(project.description, "help");
  EXPECT_EQ(project.repository_url, "https://github.com/opeolluwa/lunar");
}

TEST(ProjectTest, TechnologiesVector) {
  Project project;
  project.technologies.push_back("C++");
  project.technologies.push_back("CMake");

  ASSERT_EQ(project.technologies.size(), 2);
  EXPECT_EQ(project.technologies[0], "C++");
  EXPECT_EQ(project.technologies[1], "CMake");

  project.technologies.clear();
  EXPECT_TRUE(project.technologies.empty());
}