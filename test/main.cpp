#include <webpp_application.h>
#include <html_render.h>

int main()
{
//  webpp::webpp_application::start();
  webpp::html_render render("/Users/pengpremium/Developer/webpp/src/templates/template.html");
  render.render(5);
  return 0;
}