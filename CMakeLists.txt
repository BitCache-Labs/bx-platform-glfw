if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	set (GLFW_BUILD_WAYLAND OFF)
endif ()

# GLFW lib
add_subdirectory (extern/glfw)

## ImGui GLFW
#add_library (imgui_glfw STATIC "imgui/backends/imgui_impl_glfw.cpp")
#target_link_libraries (imgui_glfw glfw)
#target_include_directories (imgui_glfw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

add_library(bx-platform-glfw STATIC 
    "src/bx/platform/window_glfw.cpp"
	"src/bx/platform/input_glfw.cpp"
 "src/bx/platform/imgui_glfw.cpp")
target_link_libraries(bx-platform-glfw PRIVATE glfw)# imgui_glfw)
target_include_directories (bx-platform-glfw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)