cmake_minimum_required(VERSION 3.27)
project(SDLForms)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDLForms main.cpp
        Forms/Form.cpp
        Forms/Form.h
        Containers/Vector2.h
        Graphics/Renderer.cpp
        Graphics/Renderer.h
        Graphics/ColorManager.cpp
        Graphics/ColorManager.h
        Forms/Controls.cpp
        Forms/Controls.h
        Forms/IDrawable.h
        Containers/BorderStyle.h
        TestForm1.cpp
        TestForm1.h
        Containers/Vector1.h
)

target_link_libraries(
        SDLForms PRIVATE
        /Library/Frameworks/SDL2.framework/Versions/A/SDL2
        /Library/Frameworks/SDL2_image.framework/Versions/A/SDL2_image
        /Library/Frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf
)

target_include_directories(
        SDLForms PRIVATE
        /Library/Frameworks/SDL2.framework/Versions/A/Headers
        /Library/Frameworks/SDL2_image.framework/Versions/A/Headers
        /Library/Frameworks/SDL2_ttf.framework/Versions/A/Headers
)
