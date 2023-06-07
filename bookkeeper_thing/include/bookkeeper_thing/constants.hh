#pragma once

#include <imgui.h>

namespace gccore::bookkeeper_thing::constants {

ImGuiTableFlags constexpr kTableFlags =
    ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable |
    ImGuiTableFlags_Hideable | ImGuiTableFlags_BordersOuter |
    ImGuiTableFlags_BordersV;

}  // namespace gccore::bookkeeper_thing::constants
