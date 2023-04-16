// webserver_application.cpp
#include "webserver_application.hpp"

#include <boost/log/trivial.hpp>
#include <iostream>

namespace webserver
{

Application::Application(const std::string& appName)
    : d_appName(appName)
{
    BOOST_LOG_TRIVIAL(info) << "Initializing Application: " << d_appName;
}

} // namespace webserver
