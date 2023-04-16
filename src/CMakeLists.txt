add_executable(webserver webserver.m.cpp)

add_subdirectory(servicelib)

target_link_libraries(webserver
 PRIVATE
    servicelib
)