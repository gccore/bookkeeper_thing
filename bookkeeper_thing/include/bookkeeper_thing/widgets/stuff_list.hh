#pragma once

#include <bookkeeper_thing/structs/stuff.hh>
#include <bookkeeper_thing/structs/user.hh>
//
#include <cstdint>
#include <string>

namespace gccore::bookkeeper_thing::widgets {

class StuffList final {
 public:
  StuffList(structs::User::List const& user_list);

  void draw();

  void addStuff(structs::Stuff const& stuff);

 private:
  static inline uint32_t constexpr kMaxNameLen = 50U;

  structs::User::List const& users_list_;
  structs::Stuff::List stuffs_;
  structs::Stuff tmp_stuff_;
  int32_t current_user_idx_ = 0;
  int32_t tmp_price_;
};

}  // namespace gccore::bookkeeper_thing::widgets
