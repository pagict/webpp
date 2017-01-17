#include <webpp_application.h>
#include <html_render.h>
#include "root_handler.h"

using namespace webpp;
int main()
{
  webpp_application application;
  application.register_handler(std::make_shared<root_handler>());
  application.start();
  return 0;
}