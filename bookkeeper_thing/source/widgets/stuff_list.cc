#include <bookkeeper_thing/widgets/stuff_list.hh>
//
#include <imgui.h>
//
#include <cassert>

namespace gccore::bookkeeper_thing::widgets {

StuffList::StuffList(structs::User::List const& users_list)
    : users_list_(users_list)
{
}

void StuffList::draw()
{
  tmp_stuff_.name.resize(kMaxNameLen);

  ImGui::Begin("Stuff", nullptr);
  ImGui::Text("Name: ");
  ImGui::SameLine();
  ImGui::InputText(" ", tmp_stuff_.name.data(), tmp_stuff_.name.size());
  ImGui::Text("Price: ");
  ImGui::SameLine();
  ImGui::InputInt(" ", &tmp_price_);
  tmp_stuff_.price = tmp_price_;
  ImGui::Text("Users List:");
  ImGui::SameLine();
  ImGui::Combo(
      " ", &current_user_idx_,
      [](void* data, int32_t idx, char const** out) -> bool {
        assert(data && "We don't have it");
        *out = (*(structs::User::List const*)data)[idx].name.data();
        return true;
      },
      (void*)(&const_cast<structs::User::List&>(users_list_)),
      users_list_.size());

  if (ImGui::Button("Add")) {
    if (!tmp_stuff_.name.empty()) {
      structs::Stuff stuff;
    }
  }
  ImGui::End();
}

void StuffList::addStuff(structs::Stuff const& stuff)
{
  stuffs_.push_back(stuff);
}

}  // namespace gccore::bookkeeper_thing::widgets
