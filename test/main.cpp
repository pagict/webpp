#include <webpp_application.h>
#include <template_render.h>

using namespace webpp;
int main()
{
  webpp_application application;

  struct
  {
      http_response operator()(const http_request& request)
      {
        http_response response;
        response.render = template_render("src/templates/template.html");
        return response;
      }
  } rootHandler;
  application.register_handler(std::make_shared<path_handler>("/", rootHandler));


  application.start();
  return 0;
}