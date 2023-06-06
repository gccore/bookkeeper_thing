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
  ImGui::InputText("Name", tmp_stuff_.name.data(), tmp_stuff_.name.size());
  ImGui::InputScalar("Price", ImGuiDataType_U32, &tmp_price_);
  tmp_stuff_.price = tmp_price_;

  ImGui::RadioButton("Public Stuff", &radio_btn_idx_, structs::Stuff::ST_Public);
  ImGui::SameLine();
  ImGui::RadioButton("Personal Stuff", &radio_btn_idx_,
                     structs::Stuff::ST_Personal);

  if (radio_btn_idx_ == structs::Stuff::ST_Personal) {
    ImGui::Combo(
        "User List", &current_user_idx_,
        [](void* data, int32_t idx, char const** out) -> bool {
          assert(data && "We don't have it");
          *out = (*(structs::User::List const*)data)[idx].name.data();
          return true;
        },
        (void*)(&const_cast<structs::User::List&>(users_list_)),
        users_list_.size());
  }

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
