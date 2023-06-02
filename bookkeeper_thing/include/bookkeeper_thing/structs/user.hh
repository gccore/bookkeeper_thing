#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace gccore::bookkeeper_thing::structs {

struct User final {
  using List = std::vector<User>;

  std::string name;
  int32_t dept;

  bool operator==(User const& other) const;
};

}  // namespace gccore::bookkeeper_thing::structs
