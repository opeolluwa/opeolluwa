#include <string>
#include <vector>

struct Project {
  std::string name;
  std::string description;
  std::string repository_url;
  std::vector<std::string> technologies;
};
