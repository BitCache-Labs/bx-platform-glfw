#include "bx/platform/imgui_glfw.hpp"

#include <bx/core/macros.hpp>
#include <backends/imgui_impl_glfw.h>

bool ImGuiImpl::Initialize_Window()
{
#if defined BX_GRAPHICS_OPENGL_BACKEND
    if (!ImGui_ImplGlfw_InitForOpenGL(WindowGLFW::GetWindowPtr(), true))
#endif
    {
        BX_LOGE("Failed to initialize ImGui GLFW backend!");
        return false;
    }

    return true;
}

void ImGuiImpl::Shutdown_Window()
{
    ImGui_ImplGlfw_Shutdown();
}

void ImGuiImpl::NewFrame_Window()
{
    ImGui_ImplGlfw_NewFrame();
}

void ImGuiImpl::EndFrame_Window()
{
    // Update and Render additional Platform Windows
    // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
    //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}