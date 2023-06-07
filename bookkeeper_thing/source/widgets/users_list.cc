#include <bookkeeper_thing/widgets/users_list.hh>
//
#include <bookkeeper_thing/constants.hh>
//
#include <imgui.h>

namespace gccore::bookkeeper_thing::widgets {

structs::User::List const& UsersList::userList() const
{
  return users_list_;
}

void UsersList::draw()
{
  int32_t constexpr kMaxColumn = 2;

  name_.resize(kMaxNameLen);

  ImGui::Begin("Users", nullptr);
  if (ImGui::Button("Add")) {
    addUser(name_);
    name_.clear();
    name_.resize(kMaxNameLen);
  }
  ImGui::SameLine();
  ImGui::InputText("Name", name_.data(), name_.size());

  if (ImGui::BeginTable("Users", kMaxColumn, constants::kTableFlags)) {
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
