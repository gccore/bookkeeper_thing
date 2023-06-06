#pragma once

#include <bookkeeper_thing/structs/user.hh>
//
#include <string>
#include <vector>

namespace gccore::bookkeeper_thing::widgets {

class UsersList final {
 public:
  structs::User::List const& userList() const;

  void draw();

  void addUser(std::string const& name);

 private:
  static inline uint32_t constexpr kMaxNameLen = 50U;
  
  structs::User::List users_list_;
  std::string name_;
};

}  // namespace gccore::bookkeeper_thing::widgets
