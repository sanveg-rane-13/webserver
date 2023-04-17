#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "servicelib/webserver_application.hpp"

namespace
{
static const std::string APP_NAME = "WEBSERVER";
static const int PORT_NUMBER = 8080;
} // namespace

int main(int argc, char** argv)
{
    try
    {
        const auto application =
            std::make_shared<webserver::Application>(APP_NAME, PORT_NUMBER);

        assert(application);

        application->start();

        application->stop();
    }
    catch (const std::exception& e)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}