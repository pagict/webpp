//
// Created by PengPremium on 17/1/16.
//

#ifndef WEBPP_PATH_HANDLER_H
#define WEBPP_PATH_HANDLER_H

#include <headers/http_message.h>
namespace webpp
{
    class path_handler
    {
     public:
      path_handler(const string& path) : path(path) {}
      virtual http_response handle_request(const http_request& request) = 0;

      const string& get_path() { return path; }
     private:
      const string path;
    };
}

#endif //WEBPP_PATH_HANDLER_H
