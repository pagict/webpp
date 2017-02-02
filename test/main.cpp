#include <webpp_application.h>
#include <template_render.h>
#include "string_renderable.h"

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
        shared_ptr<renderable> title(new string_renderable("Hey title"));
        response.render.set_variable("Title", title);
        return response;
      }
  } rootHandler;
  application.register_handler(std::make_shared<path_handler>("/", rootHandler));


  application.start();
  return 0;
}