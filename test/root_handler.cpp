//
// Created by PengPremium on 17/1/16.
//

#include "root_handler.h"

namespace webpp
{
    http_response root_handler::handle_request(const http_request &request)
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
}