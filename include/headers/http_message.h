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
    static std::map<std::string, std::string> default_http_headers =
        {
            {"CONTENT_TYPE", "text/html"},
            {"ACCEPT",       "text/html; text/plain"},
            {"CONNECTION",   "keep-alive"}
        };


    class http_message {
     public:
      http_message();

      void set_header(const string &key, const string &value);

      void set_payload(const string &payload);

      const string& get_header(const string &key) const;

      friend std::ostream &operator<<(std::ostream &stream, http_message const &msg);

     protected:
      map<string, string> headers;
      string payload;
    };


    class http_request : public http_message
    {
     public:
      http_request(char** const envp);
    };

    class http_response : public http_message
    {
    };
}

#endif //WEBPP_HTTPMESSAGE_H
