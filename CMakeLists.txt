cmake_minimum_required(VERSION 3.16)

project(imdemo VERSION 0.1 LANGUAGES C CXX)

include(GNUInstallDirs)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

find_package(ECM 1.4.0 REQUIRED)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

find_package(Qt5 REQUIRED COMPONENTS Core Gui Quick Widgets Xml DBus)
find_package(Qt5Gui ${REQUIRED_QT5_VERSION} REQUIRED Private)
find_package(Fcitx5Qt5DBusAddons REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(WaylandScanner REQUIRED)

pkg_check_modules(xkbcommon REQUIRED IMPORTED_TARGET xkbcommon)
pkg_check_modules(xkeyboard-config REQUIRED IMPORTED_TARGET xkeyboard-config)
pkg_check_modules(wayland-client REQUIRED IMPORTED_TARGET wayland-client)
pkg_check_modules(wayland-server REQUIRED IMPORTED_TARGET wayland-server)

add_library(wayland_protocols OBJECT)

ecm_add_wayland_server_protocol(wayland_protocols
  PROTOCOL misc/wayland-protocols/input-method-unstable-v2.xml
  BASENAME input-method-unstable-v2
)

ecm_add_wayland_server_protocol(wayland_protocols
  PROTOCOL misc/wayland-protocols/virtual-keyboard-unstable-v1.xml
  BASENAME virtual-keyboard-unstable-v1
)

ecm_add_wayland_server_protocol(wayland_protocols
  PROTOCOL misc/wayland-protocols/text-input-unstable-v3.xml
  BASENAME text-input-unstable-v3
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(wl_server)
add_subdirectory(src)
