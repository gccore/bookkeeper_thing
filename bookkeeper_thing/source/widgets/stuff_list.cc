#include <bookkeeper_thing/widgets/stuff_list.hh>
//
#include <bookkeeper_thing/constants.hh>
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

  char const* const StuffTypesNameStr[] = {"Public", "Personal"};

  ImGui::RadioButton(StuffTypesNameStr[structs::Stuff::ST_Public],
                     &radio_btn_idx_, structs::Stuff::ST_Public);
  ImGui::SameLine();
  ImGui::RadioButton(StuffTypesNameStr[structs::Stuff::ST_Personal],
                     &radio_btn_idx_, structs::Stuff::ST_Personal);

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

    int32_t constexpr kMaxUserColumns = 1;
    if (ImGui::BeginTable("Users", kMaxUserColumns, constants::kTableFlags)) {
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

  /* Name | Price | Count | Type | Consumers */
  int32_t constexpr kMaxStuffColumns = 5;
  enum StuffColName { SN_Name, SN_Price, SN_Count, SN_Type, SN_Consumers };
  char const* const StuffColNameStr[] = {"Name", "Price", "Count", "Type",
                                         "Consumers"};
  if (ImGui::BeginTable("Stuff", kMaxStuffColumns, constants::kTableFlags)) {
    ImGui::TableSetupColumn(StuffColNameStr[SN_Name]);
    ImGui::TableSetupColumn(StuffColNameStr[SN_Price]);
    ImGui::TableSetupColumn(StuffColNameStr[SN_Count]);
    ImGui::TableSetupColumn(StuffColNameStr[SN_Type]);
    ImGui::TableSetupColumn(StuffColNameStr[SN_Consumers]);
    ImGui::TableHeadersRow();

    stuffs_.push_back(tmp_stuff_);
    tmp_stuff_ = structs::Stuff();

    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(SN_Name);
    ImGui::Text("%s", stuffs_.back().name.c_str());
    ImGui::TableSetColumnIndex(SN_Price);
    ImGui::Text("%u", stuffs_.back().price);
    ImGui::TableSetColumnIndex(SN_Count);
    ImGui::Text("%u", stuffs_.back().count);
    ImGui::TableSetColumnIndex(SN_Type);
    ImGui::Text("%s", stuffs_.back().type == structs::Stuff::ST_Public
                          ? StuffTypesNameStr[structs::Stuff::ST_Public]
                          : StuffTypesNameStr[structs::Stuff::ST_Personal]);
    ImGui::TableSetColumnIndex(SN_Consumers);
    int32_t tmp_idx = 0;
    ImGui::Combo(
        " ", &tmp_idx,
        [](void* data, int32_t idx, char const** out) -> bool {
          assert(data && "We don't have it");
          *out = (*(structs::Stuff::List const*)data)[idx].name.data();
          return true;
        },
        (void*)(stuffs_.back()), stuffs_.back().consumers.size());

    ImGui::EndTable();
  }

  ImGui::End();
}

void StuffList::addStuff(structs::Stuff const& stuff)
{
  stuffs_.push_back(stuff);
}

}  // namespace gccore::bookkeeper_thing::widgets
