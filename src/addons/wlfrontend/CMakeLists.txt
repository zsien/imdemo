set(WLFRONTEND_SOURCES
  WLFrontend.h
  WLFrontend.cpp
  DimTextInputV1.h
  DimTextInputV1.cpp
)

add_library(wlfrontend SHARED
  ${WLFRONTEND_SOURCES}
)

target_link_libraries(wlfrontend PRIVATE
  dimcore
  Qt6::Core
  Qt6::DBus
  PkgConfig::wayland-client
  PkgConfig::xkbcommon
  wlc
)

install(TARGETS wlfrontend
  LIBRARY DESTINATION ${DIM_ADDON_DIR}
)

install(FILES wlfrontend.conf
  DESTINATION ${DIM_ADDON_INFO_DIR}
)
