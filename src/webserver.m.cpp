#include <cstdlib>
#include <iostream>
#include <thread>

#include "servicelib/webserver_application.hpp"

namespace
{
static const std::string APP_NAME = "WEBSERVER";
}

int main(int argc, char** argv)
{

    const auto application = std::make_shared<webserver::Application>(APP_NAME);

    application->start();

    // TODO: wait till application listens to PORT

    application->stop();

    return EXIT_SUCCESS;
}