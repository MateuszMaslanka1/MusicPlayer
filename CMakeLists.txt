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
    QML_FILES Player/PlayerContent/SinglePlayList.qml
    SOURCES playlists.h playlists.cpp
    SOURCES playlist.h
    SOURCES
    SOURCES DecodeMusicData/decodemusicdata.h DecodeMusicData/decodemusicdata.cpp
    SOURCES SongDetails.h
    RESOURCES icons/play.svg
    RESOURCES icons/trash-fill.svg
    RESOURCES icons/skip-backward-fill.svg icons/skip-forward-fill.svg
)

target_link_libraries(appMusicPlayer
    PRIVATE Qt6::Multimedia
    PRIVATE Qt6::Quick
)

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
