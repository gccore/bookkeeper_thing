#pragma once

#include <bookkeeper_thing/structs/user.hh>
//
#include <string>
#include <vector>

namespace gccore::bookkeeper_thing::widgets {

class UsersList final {
 public:
  void draw();

  void addUser(std::string const& name);

 private:
  structs::User::List users_list_;
};

}  // namespace gccore::bookkeeper_thing::widgets
