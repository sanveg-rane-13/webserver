add_executable(webserver webserver.m.cpp)

add_subdirectory(servicelib)

# link local libs
target_link_libraries(webserver
 PRIVATE
    servicelib
)