#include <bookkeeper_thing/version.hh>
//
#include <iostream>

namespace {
void PrintHelloMessage()
{
  using namespace gccore::bookkeeper_thing;
  std::cout << "[Starting: " << kName << "-" << kVersion << "v]" << std::endl;
}
void PrintByMessage()
{
  using namespace gccore::bookkeeper_thing;
  std::cout << "[Closing]: " << kName << "-" << kVersion << "v]" << std::endl;
}
}  // namespace

int main()
{
  PrintHelloMessage();
  PrintByMessage();
}
