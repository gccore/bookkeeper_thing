#include <bookkeeper_thing/version.hh>
#include <bookkeeper_thing/widgets/users_list.hh>
//
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
//
#include <cassert>
#include <iostream>
#include <string_view>

static void GlfwErrorCallback(int32_t error, char const* msg)
{
  std::cerr << "GLFW Error: " << error << ", " << msg << std::endl;
}

int main()
{
  glfwSetErrorCallback(GlfwErrorCallback);
  assert(glfwInit() && "Couldn't init the GLFW things");
  if (!glfwInit()) std::exit(EXIT_FAILURE);

  auto constexpr kGLSLVersion = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  GLFWwindow* const window = glfwCreateWindow(
      800, 600, gccore::bookkeeper_thing::kName, nullptr, nullptr);
  assert(window && "Couldn't create the window");
  if (window == nullptr) std::exit(EXIT_FAILURE);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& imgui_io = ImGui::GetIO();
  imgui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  imgui_io.Fonts->AddFontFromFileTTF(GCCORE_IMGUI_FONT_PATH, 20.0f);

  ImGui::StyleColorsLight();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(kGLSLVersion);

  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.6f, 1.0f);

  using namespace gccore::bookkeeper_thing;
  widgets::UsersList user_list;

  std::string username;
  username.resize(50);
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Users", nullptr);
    user_list.draw();

    ImGui::InputText("Name", username.data(), username.size());
    if (ImGui::Button("Add")) {
      if (!username.empty()) {
        user_list.addUser(username);
        username.clear();
        username.resize(50);
      }
    }
    ImGui::End();

    ImGui::Render();
    int32_t display_w = 0;
    int32_t display_h = 0;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  std::exit(EXIT_SUCCESS);
}
