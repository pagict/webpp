//
// Created by PengPremium on 17/1/14.
//

#include <iostream>
#include <fcgiapp.h>
#include <fcgio.h>
#include <webpp_application.h>

using std::cin;
using std::cout;
using std::cerr;

namespace webpp
{
    streambuf *cin_streambuf;
    streambuf *cout_streambuf;
    streambuf *cerr_streambuf;
    /**
     * @brief start the application, start listening and accept request.
     */
    void webpp_application::start()
    {
      cin_streambuf = cin.rdbuf();
      cout_streambuf = cout.rdbuf();
      cerr_streambuf = cerr.rdbuf();

      FCGX_Request cgi_request;
      FCGX_Init();
      FCGX_InitRequest(&cgi_request, 0, 0);

      // Here comes a request
      while (FCGX_Accept_r(&cgi_request) == 0)
      {
        fcgi_streambuf cin_fcgi_streambuf(cgi_request.in);
        fcgi_streambuf cout_fcgi_streambuf(cgi_request.out);
        fcgi_streambuf cerr_fcgi_streambuf(cgi_request.err);

        // Read headers
        http_request request(cgi_request.envp);

        const string uri = request.get_header("REQUEST_URI");

        // Iterate the handlers to find the matched handler.
        // Iterate in inverse order.
        auto iter = handlers.rbegin();
        while (iter != handlers.rend())
        {
          if (iter->get()->get_path().compare(uri) == 0) break;
          iter++;
        }
        // If no handler matched, use the default, thus the first handler, returns nothing.
        if (iter == handlers.rend())
        {
          iter--;
        }

        auto response = iter->get()->operator()(request);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        cout << response;
      }
    }


    /**
     * @brief push back a handler to the list
     * @param handle handler to be inserted
     */
    void webpp_application::register_handler(std::shared_ptr<path_handler> handle)
    {
      this->handlers.push_back(handle);
    }

    /**
     * @brief default handler
     */
    struct
    {
        http_response operator()(const http_request &request)
        {
          return (http_response());
        }
    } handler;

    /**
     * @brief insert the default handler
     */
    webpp_application::webpp_application()
    {
      register_handler(make_shared<path_handler>("", handler));
    }

    /**
     * @brief recover the cin, cout, cerr.
     */
    webpp_application::~webpp_application()
    {
      cin.rdbuf(cin_streambuf);
      cout.rdbuf(cout_streambuf);
      cerr.rdbuf(cerr_streambuf);
    }
}
