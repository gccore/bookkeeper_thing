#include <bookkeeper_thing/widgets/users_list.hh>
//
#include <imgui.h>

namespace gccore::bookkeeper_thing::widgets {

void UsersList::draw()
{
  ImGuiTableFlags constexpr kFlags =
      ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable |
      ImGuiTableFlags_Hideable | ImGuiTableFlags_BordersOuter |
      ImGuiTableFlags_BordersV;
  int32_t constexpr kMaxColumn = 2;

  if (ImGui::BeginTable("Users", kMaxColumn, kFlags)) {
    ImGui::TableSetupColumn("Name");
    ImGui::TableSetupColumn("Debt");
    ImGui::TableHeadersRow();

    for (size_t row_idx = 0; row_idx < users_list_.size(); ++row_idx) {
      ImGui::TableNextRow();
      for (size_t col_idx = 0; col_idx < kMaxColumn; ++col_idx) {
        ImGui::TableSetColumnIndex(col_idx);
        ImGui::Text("%s", users_list_.at(row_idx).c_str());
      }
    }
    ImGui::EndTable();
  }
}

void UsersList::addUser(std::string const& name)
{
  users_list_.push_back(name);
}

}  // namespace gccore::bookkeeper_thing::widgets
