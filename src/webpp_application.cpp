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
    void webpp_application::start()
    {
      streambuf *cin_streambuf = cin.rdbuf();
      streambuf *cout_streambuf = cout.rdbuf();
      streambuf *cerr_streambuf = cerr.rdbuf();

      FCGX_Request cgi_request;
      FCGX_Init();
      FCGX_InitRequest(&cgi_request, 0, 0);
      while (FCGX_Accept_r(&cgi_request) == 0)
      {
        fcgi_streambuf cin_fcgi_streambuf(cgi_request.in);
        fcgi_streambuf cout_fcgi_streambuf(cgi_request.out);
        fcgi_streambuf cerr_fcgi_streambuf(cgi_request.err);

        http_request request;

        char** env = cgi_request.envp;
        const string EQUAL_SIGN = "=";
        while (*(env))
        {
          string kv_pair(*env);
          size_t equal_idx = kv_pair.find(EQUAL_SIGN);
          if (equal_idx == string::npos) break;
          request.set_header(kv_pair.substr(0, equal_idx), kv_pair.substr(equal_idx+1));

          env++;
        }

        const string uri = request.get_header("REQUEST_URI");

        auto iter = handlers.rbegin();
        while (iter != handlers.rend())
        {
          if (iter->get()->get_path().compare(uri) == 0) break;
          iter++;
        }
        if (iter == handlers.rend())
        {
          //TODO: handle error
        }

        auto response = iter->get()->handle_request(request);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        http_message responseMessage;
        cout << response;
      }

      cin.rdbuf(cin_streambuf);
      cout.rdbuf(cout_streambuf);
      cerr.rdbuf(cerr_streambuf);
    }


    void webpp_application::register_handler(std::shared_ptr<path_handler> handle)
    {
      this->handlers.push_back(handle);
    }
}
