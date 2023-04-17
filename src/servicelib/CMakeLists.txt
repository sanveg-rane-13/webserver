add_library(servicelib "")

# link 3rd party libraries
find_package(Boost COMPONENTS program_options log log_setup REQUIRED)
target_link_libraries(servicelib
  ${Boost_LIBRARIES}
  ${Boost_LOG_LIBRARY} 
  ${Boost_LOG_SETUP_LIBRARY}
)

target_sources(servicelib
 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/webserver_application.cpp
  ${CMAKE_CURRENT_LIST_DIR}/webserver_httpsacceptor.cpp
 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/webserver_application.hpp
  ${CMAKE_CURRENT_LIST_DIR}/webserver_httpsacceptor.hpp
)

target_include_directories(servicelib
 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
