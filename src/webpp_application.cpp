//
// Created by PengPremium on 17/1/14.
//

#include <iostream>
#include <fcgiapp.h>
#include <fcgio.h>
#include <webpp_application.h>

#include <headers/http_message.h>

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

      FCGX_Request request;
      FCGX_Init();
      FCGX_InitRequest(&request, 0, 0);
      while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);
        char *param;
        try {
          param = FCGX_GetParam("Header", request.envp);
        } catch (exception e) {

        }

        unsigned long content_length = 2048;
        char *content_len_str = FCGX_GetParam("CONTENT_LENGTH", request.envp);
        if (content_len_str) {
          content_length = stol(content_len_str);
        }

        char_type *content_buff = new char_type[content_length];
        cin.read(content_buff, content_length);
        content_length = cin.gcount();

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        http_message responseMessage;
        responseMessage.setHeader("Content-Type", "text/html");
        string payload =
            "<html>\n"
                " <head>\n"
                "   <title>Hello Title</title>\n"
                " </head>\n"
                " <body>\n"
                "   <h1>Hello body, hot body</h1>\n"
                " </body>\n"
                "</html>\n";
        responseMessage.setPayload(payload);
        cout << responseMessage;
      }

      cin.rdbuf(cin_streambuf);
      cout.rdbuf(cout_streambuf);
      cerr.rdbuf(cerr_streambuf);
    }
}
