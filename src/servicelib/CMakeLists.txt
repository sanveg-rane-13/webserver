add_library(servicelib "")

target_sources(servicelib
 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/webserver_initializer.cpp
 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/webserver_initializer.hpp
)

target_include_directories(servicelib
 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
