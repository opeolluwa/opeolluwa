#include <include/projects.hpp>
#include <vector>

const std::vector<Project> featured_projects = {
    Project{
      name : "Lunar",
      description : "Some description",
      repository_url : "https://github.com/opeolluwa/lunar",
      technologies : {"Nuxt", "Pinia", "Rust", "Android", "Tauri"}
    },
};
