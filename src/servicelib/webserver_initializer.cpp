// webserver_initializer.cpp
#include "webserver_initializer.hpp"

#include <iostream>

namespace webserver
{

WebServer::WebServer(const std::string& appName)
    : d_appName(appName)
{
    std::cout << "Starting: " << d_appName << std::endl;
}

} // namespace webserver
