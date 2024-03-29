set(FCITX5PROXY_SOURCES
  Fcitx5Proxy.h
  Fcitx5Proxy.cpp
  DBusProvider.h
  DBusProvider.cpp
  BatchEvent.h
  BatchEvent.cpp
)

set_source_files_properties(${CMAKE_SOURCE_DIR}/misc/fcitx5-inputcontext.xml
  PROPERTIES INCLUDE "BatchEvent.h"
)
qt_add_dbus_interface(IC_SOURCES
  ${CMAKE_SOURCE_DIR}/misc/fcitx5-inputcontext.xml
  Fcitx5InputContextIface
)

add_library(fcitx5proxy MODULE
  ${FCITX5PROXY_SOURCES}
  ${IC_SOURCES}
)

target_link_libraries(fcitx5proxy PRIVATE
  dimcore
  Qt6::Core
  Qt6::DBus
  Qt6::GuiPrivate
  Fcitx5Qt6::DBusAddons
)

install(TARGETS fcitx5proxy
  LIBRARY DESTINATION ${DIM_ADDON_DIR}
)

install(FILES fcitx5proxy.conf
  DESTINATION ${DIM_ADDON_INFO_DIR}
)

