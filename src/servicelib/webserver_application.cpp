// webserver_application.cpp
#include "webserver_application.hpp"

#include <boost/log/trivial.hpp>

#include <cassert>
#include <iostream>
#include <thread>

namespace webserver
{

Application::Application(const std::string& appName, const unsigned int port)
    : d_appName(appName)
{
    try
    {
        d_httpsAcceptor =
            std::make_shared<HttpsAcceptor>(port); // throws exceptions
    }
    catch (const std::exception& e)
    {
        BOOST_LOG_TRIVIAL(error)
            << "Error initializing application: " << e.what();
        std::cerr << e.what() << '\n';
    }
}

void Application::start() noexcept
{
    assert(d_httpsAcceptor);

    try
    {
        d_httpsAcceptor->start();

        // wait 10 secs to listen on port
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    catch (const std::exception& e)
    {
        BOOST_LOG_TRIVIAL(error) << "Error starting application: " << e.what();
    }
}

void Application::stop() noexcept
{
    try
    {
        d_httpsAcceptor->stop();
    }
    catch (const std::exception& e)
    {
        BOOST_LOG_TRIVIAL(error) << "Error stopping application: " << e.what();
    }
}

} // namespace webserver
