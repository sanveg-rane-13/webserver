// webserver_application.hpp
#ifndef WEBSERVER_APPLICATION
#define WEBSERVER_APPLICATION

#include <string>

namespace webserver
{

// ------------------
// class Application
// ------------------
class Application
{
  public:
    // CREATORS
    Application(const std::string& appName);

    ~Application() = default;

    // Non-copyable
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // Non-moveable
    Application(Application&&) = delete;
    Application& operator=(Application&&) = delete;

    void start();

    void stop() noexcept;

  private:
    std::string d_appName;
};

} // namespace webserver

#endif // WEBSERVER_INITIALIZER