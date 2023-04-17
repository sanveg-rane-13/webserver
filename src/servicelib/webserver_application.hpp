// webserver_application.hpp
#ifndef WEBSERVER_APPLICATION
#define WEBSERVER_APPLICATION

#include "webserver_httpsacceptor.hpp"

#include <memory>
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
    Application(const std::string& appName, const unsigned int port);

    ~Application() = default;

    // Non-copyable
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // Non-moveable
    Application(Application&&) = delete;
    Application& operator=(Application&&) = delete;

    void start() noexcept;

    void stop() noexcept;

  private:
    std::string d_appName;
    std::shared_ptr<IHttpsAcceptor> d_httpsAcceptor;
};

} // namespace webserver

#endif // WEBSERVER_INITIALIZER