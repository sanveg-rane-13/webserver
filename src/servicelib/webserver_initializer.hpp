// webserver_initializer.hpp
#ifndef WEBSERVER_INITIALIZER
#define WEBSERVER_INITIALIZER

#include <string>

namespace webserver
{

// ----------------
// class WebServer
// ----------------
class WebServer
{
  public:
    // CREATORS
    WebServer(const std::string& appName);

    ~WebServer() = default;

  private:
    std::string d_appName;
};

} // namespace webserver

#endif // WEBSERVER_INITIALIZER