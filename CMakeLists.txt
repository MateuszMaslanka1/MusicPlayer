cmake_minimum_required(VERSION 3.16)

project(MusicPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Multimedia)

# Nie dodawaj target_link_libraries tutaj, ponieważ mytarget jeszcze nie został zdefiniowany

qt_standard_project_setup()

qt_add_executable(appMusicPlayer
    main.cpp
)

qt_add_qml_module(appMusicPlayer
    URI MusicPlayer
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES Player/Player.qml
    QML_FILES Player/PlayerContent/PlayerContent.qml
    QML_FILES Player/PlayerLeftBar/PlayerLeftBar.qml
    QML_FILES Player/SharedComponents/ButtonComponent.qml
    QML_FILES Player/PlayerContent/MusicLibrary.qml
    QML_FILES Player/PlayerController/PlayerController.qml
    SOURCES MusicPlayer/musicplayer.h MusicPlayer/musicplayer.cpp
    SOURCES PlaySong/playsong.h PlaySong/playsong.cpp
    QML_FILES Player/PlayerContent/PlayLists.qml
)

target_link_libraries(appMusicPlayer
    PRIVATE Qt6::Multimedia
    PRIVATE Qt6::Quick
)

find_library(MPG123_LIBRARY NAMES mpg123)
if (MPG123_LIBRARY)
    target_link_libraries(appMusicPlayer PRIVATE ${MPG123_LIBRARY})
else()
    include(FetchContent)
    FetchContent_Declare(
        mpg123
        URL https://www.mpg123.de/download/mpg123-1.28.0.tar.bz2
    )

    FetchContent_GetProperties(mpg123)
    if(NOT mpg123_POPULATED)
        FetchContent_Populate(mpg123)
        add_subdirectory(${mpg123_SOURCE_DIR} ${mpg123_BINARY_DIR})
        target_link_libraries(appMusicPlayer PRIVATE mpg123)
    else()
        message(FATAL_ERROR "Nie można pobrać mpg123.")
    endif()
endif()

set_target_properties(appMusicPlayer PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS appMusicPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
