//
// Created by PengPremium on 17/1/5.
//

#ifndef WEBPP_HTTPMESSAGE_H
#define WEBPP_HTTPMESSAGE_H

#include <string>
#include <map>
#include <fcgio.h>
using namespace std;

namespace webpp
{
    class http_message {
     public:
      http_message();

      void setHeader(const string &key, const string &value);

      void setPayload(const string &payload);

      friend std::ostream &operator<<(std::ostream &stream, http_message const &msg);

     protected:
      map<string, string> headers;
      string payload;
    };
}

#endif //WEBPP_HTTPMESSAGE_H
