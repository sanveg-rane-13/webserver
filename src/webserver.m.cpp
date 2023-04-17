#include <cstdlib>
#include <iostream>
#include <memory>
#include <thread>

#include "servicelib/webserver_application.hpp"

namespace
{
static const std::string APP_NAME = "WEBSERVER";
static const int PORT_NUMBER = 8080;
} // namespace

int main(int argc, char** argv)
{

    const auto application =
        std::make_shared<webserver::Application>(APP_NAME, PORT_NUMBER);

    application->start();

    // wait 5 secs to listen on port
    std::this_thread::sleep_for(std::chrono::seconds(60 * 5));

    application->stop();

    return EXIT_SUCCESS;
}