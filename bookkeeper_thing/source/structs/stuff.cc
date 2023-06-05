#include <bookkeeper_thing/structs/stuff.hh>

namespace gccore::bookkeeper_thing::structs {

bool Stuff::operator==(Stuff const& other) const
{
  return this->name == other.name && this->price == other.price;
}

}  // namespace gccore::bookkeeper_thing::structs
