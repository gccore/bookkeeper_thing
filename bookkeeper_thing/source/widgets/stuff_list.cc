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

  ImGui::RadioButton("Public Stuff", &radio_btn_idx_,
                     structs::Stuff::ST_Public);
  ImGui::SameLine();
  ImGui::RadioButton("Personal Stuff", &radio_btn_idx_,
                     structs::Stuff::ST_Personal);

  if (radio_btn_idx_ == structs::Stuff::ST_Personal) {
    ImGui::SeparatorText("Choose the consumers");

    if (ImGui::Button("Add")) {
      tmp_stuff_.consumers.push_back(users_list_.at(current_user_idx_));
    }
    ImGui::SameLine();

    ImGui::Combo(
        "User List", &current_user_idx_,
        [](void* data, int32_t idx, char const** out) -> bool {
          assert(data && "We don't have it");
          *out = (*(structs::User::List const*)data)[idx].name.data();
          return true;
        },
        (void*)(&const_cast<structs::User::List&>(users_list_)),
        users_list_.size());

    ImGuiTableFlags constexpr kFlags =
        ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable |
        ImGuiTableFlags_Hideable | ImGuiTableFlags_BordersOuter |
        ImGuiTableFlags_BordersV;
    int32_t constexpr kMaxColumn = 1;
    if (ImGui::BeginTable("Users", kMaxColumn, kFlags)) {
      ImGui::TableSetupColumn("Name");
      ImGui::TableHeadersRow();

      for (size_t row_idx = 0; row_idx < tmp_stuff_.consumers.size();
           ++row_idx) {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s", tmp_stuff_.consumers.at(row_idx).name.c_str());
      }
      ImGui::EndTable();
    }

    ImGui::SeparatorText("=");
  }

  if (ImGui::Button("Add Stuff")) {
    if (!tmp_stuff_.name.empty()) {
      tmp_stuff_.type = structs::Stuff::Type(radio_btn_idx_);
    }
  }
  ImGui::End();
}

void StuffList::addStuff(structs::Stuff const& stuff)
{
  stuffs_.push_back(stuff);
}

}  // namespace gccore::bookkeeper_thing::widgets
