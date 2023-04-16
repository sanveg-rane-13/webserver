// webserver_initializer.cpp
#include "webserver_initializer.hpp"

#include <boost/log/trivial.hpp>
#include <iostream>

namespace webserver
{

WebServer::WebServer(const std::string& appName)
    : d_appName(appName)
{
    BOOST_LOG_TRIVIAL(info) << "Initializing webserver: " << d_appName;
}

} // namespace webserver
