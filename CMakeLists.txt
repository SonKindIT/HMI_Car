cmake_minimum_required(VERSION 3.16)

project(CarHmi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appCarHmi
    main.cpp
)

qt_add_qml_module(appCarHmi
    URI CarHmi
    QML_FILES
        Main.qml
    RESOURCES
        resouce.qrc
        SOURCES source/view/radialbar.h source/view/radialbar.cpp
        SOURCES source/view/segmentbar.h source/view/segmentbar.cpp
        SOURCES source/controller/hmicontroller.h source/controller/hmicontroller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCarHmi PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCarHmi
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCarHmi
    PRIVATE Qt6::Quick
)
target_link_libraries(appCarHmi PRIVATE Qt6::Core)
target_link_libraries(appCarHmi PRIVATE Qt6::Core)
target_link_libraries(appCarHmi PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appCarHmi
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
