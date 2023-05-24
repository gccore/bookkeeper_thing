#include <bookkeeper_thing/version.hh>
//
#include <iostream>

int main()
{
  using namespace gccore::bookkeeper_thing;
  
  std::cout << "Starting: " << kName << "-" << kVersion << "v" << std::endl;
}
