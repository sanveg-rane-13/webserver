#include <cstdlib>
#include <iostream>
#include <memory>
#include <thread>

#include "servicelib/webserver_initializer.hpp"

namespace
{

static const std::string APP_NAME = "WEBSERVER";

}

int main()
{
    std::cout << "Initializing webserver..." << std::endl;

    webserver::WebServer webserver(APP_NAME);

    return EXIT_SUCCESS;
}