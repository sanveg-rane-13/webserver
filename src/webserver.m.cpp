#include <cstdlib>
#include <iostream>

#include "servicelib/webserver_initializer.hpp"

namespace
{
static const std::string APP_NAME = "WEBSERVER";
}

int main()
{
    webserver::WebServer webserver(APP_NAME);
    return EXIT_SUCCESS;
}