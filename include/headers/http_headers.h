//
// Created by PengPremium on 17/1/14.
//

#ifndef WEBPP_HTTP_HEADERS_H
#define WEBPP_HTTP_HEADERS_H

#include <map>
#include <string>

namespace webpp
{
  static std::map<std::string, std::string> default_http_headers =
      {
          {"Content-Type", "text/html"},
          {"Accept",       "text/html; text/plain"},
          {"Connection",   "keep-alive"}
      };
}
#endif //WEBPP_HTTP_HEADERS_H
