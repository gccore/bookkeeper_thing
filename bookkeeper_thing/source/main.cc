#include <bookkeeper_thing/version.hh>
//
#include <ncurses.h>
//
#include <iostream>
#include <string>

using namespace gccore::bookkeeper_thing;

auto const kTagedName = std::string(kName) + "-" + kVersion;
auto const kStartMsg = "[STARTING]: " + kTagedName + "v";
auto const kEndMsg = "[CLOSING]: " + kTagedName + "v";

namespace {
void PrintHelloMsg()
{
  using namespace gccore::bookkeeper_thing;
  ::printw("%s\n", (kStartMsg).c_str());
}
void PrintBayMsg()
{
  using namespace gccore::bookkeeper_thing;
  ::printw("%s\n", (kEndMsg).c_str());
}
}  // namespace

int main()
{
  initscr();
  PrintHelloMsg();
  PrintBayMsg();
  refresh();
  getch();
  endwin();

  return EXIT_SUCCESS;
}
