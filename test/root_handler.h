//
// Created by PengPremium on 17/1/16.
//

#ifndef WEBPP_ROOT_HANDLER_H
#define WEBPP_ROOT_HANDLER_H

#include "path_handler.h"
namespace webpp
{
    class root_handler : public path_handler
    {
     public:
      root_handler() : path_handler("/") {}
      http_response handle_request(const http_request& request);
    };
}

#endif //WEBPP_ROOT_HANDLER_H
