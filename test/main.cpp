#include <webpp_application.h>
#include <html_render.h>

using namespace webpp;
int main()
{
  webpp_application application;

  struct
  {
      http_response operator()(const http_request& request)
      {
        http_response response;
        string payload =
            "<html>\n"
                " <head>\n"
                "   <title>Hello Title</title>\n"
                " </head>\n"
                " <body>\n"
                "   <h1>Hello body, hot body</h1>\n"
                " </body>\n"
                "</html>\n";
        response.set_payload(payload);
        return response;
      }
  } rootHandler;
  application.register_handler(std::make_shared<path_handler>("/", rootHandler));


  application.start();
  return 0;
}