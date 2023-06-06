#include <bookkeeper_thing/widgets/users_list.hh>
//
#include <imgui.h>

namespace gccore::bookkeeper_thing::widgets {

structs::User::List const& UsersList::userList() const
{
  return users_list_;
}

void UsersList::draw()
{
  ImGuiTableFlags constexpr kFlags =
      ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable |
      ImGuiTableFlags_Hideable | ImGuiTableFlags_BordersOuter |
      ImGuiTableFlags_BordersV;
  int32_t constexpr kMaxColumn = 2;

  name_.resize(kMaxNameLen);

  ImGui::Begin("Users", nullptr);
  ImGui::Text("Name:");
  ImGui::SameLine();
  ImGui::InputText(" ", name_.data(), name_.size());
  ImGui::SameLine();
  if (ImGui::Button("Add")) {
    if (!name_.empty()) {
      addUser(name_);
      name_.clear();
      name_.resize(kMaxNameLen);
    }
  }

  if (ImGui::BeginTable("Users", kMaxColumn, kFlags)) {
    ImGui::TableSetupColumn("Name");
    ImGui::TableSetupColumn("Debt");
    ImGui::TableHeadersRow();

    for (size_t row_idx = 0; row_idx < users_list_.size(); ++row_idx) {
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Text("%s", users_list_[row_idx].name.c_str());
      ImGui::TableSetColumnIndex(1);
      ImGui::Text("%u", users_list_[row_idx].dept);
    }
    ImGui::EndTable();
  }
  ImGui::End();
}

void UsersList::addUser(std::string const& name)
{
  structs::User new_user;
  new_user.name = name;
  users_list_.push_back(new_user);
}

}  // namespace gccore::bookkeeper_thing::widgets
