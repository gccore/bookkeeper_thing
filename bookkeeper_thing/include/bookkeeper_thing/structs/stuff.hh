#pragma once

#include <bookkeeper_thing/structs/user.hh>
//
#include <cstdint>
#include <string>
#include <vector>

namespace gccore::bookkeeper_thing::structs {

struct Stuff final {
  using List = std::vector<Stuff>;

  enum Type { ST_Personal, ST_Public };

  std::string name;
  uint32_t price = 0;
  uint32_t count = 0;
  Type type;
  User::List consumers;

  bool operator==(Stuff const& other) const;
};

}  // namespace gccore::bookkeeper_thing::structs
