// webserver_httpsacceptor.hpp
#ifndef WEBSERVER_HTTPSACCEPTOR
#define WEBSERVER_HTTPSACCEPTOR

#include <atomic>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

namespace webserver
{

class IHttpsAcceptor
{
  public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

// ------------------
// class HttpsAcceptor
// ------------------
class HttpsAcceptor : public IHttpsAcceptor
{
  public:
    explicit HttpsAcceptor(const unsigned int port);
    ~HttpsAcceptor() = default;

    // Non-copyable
    HttpsAcceptor(const HttpsAcceptor&) = delete;
    HttpsAcceptor& operator=(const HttpsAcceptor&) = delete;

    void start();

    void stop();

  private:
    const unsigned int d_port;
    boost::asio::io_service d_ioService;
    boost::asio::ip::tcp::acceptor d_tcpAcceptor;
    boost::asio::ssl::context d_sslContext;
};

} // namespace webserver

#endif // WEBSERVER_HTTPSACCEPTOR