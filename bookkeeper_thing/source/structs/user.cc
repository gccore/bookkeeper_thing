#include <bookkeeper_thing/structs/user.hh>

namespace gccore::bookkeeper_thing::structs {

bool User::operator==(User const& other) const
{
  return this->name == other.name;
}

}  // namespace gccore::bookkeeper_thing::structs
