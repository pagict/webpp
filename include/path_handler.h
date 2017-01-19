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
      typedef std::function<http_response(const http_request&)> handle_func_type;

      path_handler(const string& path, handle_func_type func)
          : path(path), handle_function(func)
      {}

      const string& get_path() const { return path; }

      inline http_response operator()(const http_request& request)
      {
          return handle_function.operator()(request);
      }

     private:
      const string path;
      handle_func_type handle_function;
    };
}

#endif //WEBPP_PATH_HANDLER_H
