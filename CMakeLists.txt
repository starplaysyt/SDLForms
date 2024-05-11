cmake_minimum_required(VERSION 3.27)
project(SDLForms)
file(COPY Fonts/font.ttf
        DESTINATION ./)

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
        Forms/IControl.h
        TestForm1.cpp
        TestForm1.h
        Graphics/TextRenderer.cpp
        Graphics/TextRenderer.h
        Enums/FormEnums.h
        Events/MouseMoveEventArgs.h
        Events/MouseEventType.h
        Events/MouseEventArgs.h
)

if (WIN32)
    set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2-2.30.3/include")
    set(SDL2_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2-2.30.3/lib/x64")
    set(SDL2_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_image-2.8.2/include")
    set(SDL2_IMAGE_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_image-2.8.2/lib/x64")
    set(SDL2_TTF_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_ttf-2.22.0/include")
    set(SDL2_TTF_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2_ttf-2.22.0/lib/x64")

    target_link_libraries(
            SDLForms
            ${SDL2_LIBRARY_DIR}/SDL2main.lib
            ${SDL2_LIBRARY_DIR}/SDL2.lib
            ${SDL2_IMAGE_LIBRARY_DIR}/SDL2_image.lib
            ${SDL2_TTF_LIBRARY_DIR}/SDL2_ttf.lib
    )

    target_include_directories(
            SDLForms PRIVATE
            ${SDL2_INCLUDE_DIR}
            ${SDL2_IMAGE_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
    )
endif (WIN32)

if (UNIX)
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
endif (UNIX)


