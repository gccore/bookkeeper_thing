#pragma once

#include <string>
#include <vector>

namespace gccore::bookkeeper_thing::widgets {

class UsersList final {
 public:
  void draw();

  void addUser(std::string const& name);

 private:
  std::vector<std::string> users_list_;
};

}  // namespace gccore::bookkeeper_thing::widgets
