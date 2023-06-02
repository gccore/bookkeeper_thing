#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace gccore::bookkeeper_thing::structs {

struct User final {
  using List = std::vector<User>;

  std::string name;
  uint32_t dept = 0;

  bool operator==(User const& other) const;
};

}  // namespace gccore::bookkeeper_thing::structs
