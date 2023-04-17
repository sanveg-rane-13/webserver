// webserver_application.cpp
#include "webserver_application.hpp"

#include <boost/log/trivial.hpp>
#include <iostream>

namespace webserver
{

Application::Application(const std::string& appName, const unsigned int port)
    : d_appName(appName)
    , d_httpsAcceptor(std::make_shared<HttpsAcceptor>(port))
{}

void Application::start()
{
    BOOST_LOG_TRIVIAL(info) << "Starting application " << d_appName;

    d_httpsAcceptor->start();
}

void Application::stop() noexcept
{
    BOOST_LOG_TRIVIAL(info) << "Stopping application " << d_appName;

    d_httpsAcceptor->stop();
}

} // namespace webserver
