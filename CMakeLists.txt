cmake_minimum_required(VERSION 3.16)

project(nitrous VERSION 0.7 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools)

set(LIBUSB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/libusb-1.0.27/include")
set(LIBUSB_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/lib/libusb-1.0.27/MinGW64/static/libusb-1.0.a")

set(TS_FILES "${CMAKE_CURRENT_SOURCE_DIR}/locale/nitrous_en_US.ts")

set(PROJECT_SOURCES
    src/main.cpp
    src/main.h
    src/main.ui
    src/status.h
    src/status.cpp
    src/connect.h
    src/connect.cpp
    src/directory.h
    src/directory.cpp
    src/browser.h
    src/browser.cpp
    src/preferences.h
    src/preferences.cpp
    src/about.h
    src/about.cpp
    src/console.h
    src/console.cpp
    ${TS_FILES}
)
set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.rc")

set(resources "${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.qrc")

qt_add_executable(nitrous
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    ${app_icon_resource_windows}
    ${resources}
    src/config.h src/config.cpp
    src/config_data.h
    src/config_file_handler.h src/config_file_handler.cpp
)

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_include_directories(nitrous PRIVATE ${LIBUSB_INCLUDE_DIR})
target_link_libraries(nitrous PRIVATE Qt6::Widgets ${LIBUSB_LIBRARY})

set_target_properties(nitrous PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS nitrous
    BUNDLE DESTINATION ${CMAKE_INSTALL_PREFIX}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(nitrous)
