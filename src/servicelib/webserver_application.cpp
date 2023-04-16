// webserver_application.cpp
#include "webserver_application.hpp"

#include <boost/log/trivial.hpp>
#include <iostream>

namespace webserver
{

Application::Application(const std::string& appName)
    : d_appName(appName)
{}

void Application::start()
{
    BOOST_LOG_TRIVIAL(info) << "Starting application " << d_appName;
}

void Application::stop() noexcept
{
    BOOST_LOG_TRIVIAL(info) << "Stopping application " << d_appName;
}

} // namespace webserver
