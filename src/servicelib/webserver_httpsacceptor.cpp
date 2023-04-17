// webserver_httpsacceptor.cpp
#include "webserver_httpsacceptor.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/log/trivial.hpp>

namespace webserver
{

// initialize TCP endpoint with IPv4 and ssl context with sslv23 server
HttpsAcceptor::HttpsAcceptor(const unsigned int port)
    : d_port(port)
    , d_ioService()
    , d_tcpAcceptor(
          d_ioService,
          asio::ip::tcp::endpoint(asio::ip::address_v4::any(), d_port))
    , d_sslContext(asio::ssl::context::sslv23_server)
{
    // setting up the ssl context.
    d_sslContext.set_options(boost::asio::ssl::context::default_workarounds |
                             boost::asio::ssl::context::no_sslv2 |
                             boost::asio::ssl::context::single_dh_use);

    // set ssl certification file
    m_SSLContext.use_certificate_chain_file("HttpsWebServer.cert");
    // set ssl private key file
    m_SSLContext.use_private_key_file("HttpsWebServer.key",
                                      boost::asio::ssl::context::pem);

    BOOST_LOG_TRIVIAL(info) << "Initialized https acceptor on port " << d_port;
}

void HttpsAcceptor::start()
{}

void HttpsAcceptor::stop()
{}

} // namespace webserver