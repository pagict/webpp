//
// Created by PengPremium on 17/1/5.
//

#ifndef WEBPP_HTTPMESSAGE_H
#define WEBPP_HTTPMESSAGE_H

#include <string>
#include <map>
#include <fcgio.h>
#include <template_render.h>
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

//      void set_payload(const string &payload);

      const string& get_header(const string &key) const;

      friend std::ostream &operator<<(std::ostream &stream, const http_message &msg) ;

     protected:
      map<string, string> headers;

      string headers_string() const;
    };


    class http_request : public http_message
    {
     public:
      http_request(char** const envp);
    };

    class http_response : public http_message
    {
     public:
      friend std::ostream& operator<<(std::ostream &stream, const http_response& response);

      template_render render;
    };
}

#endif //WEBPP_HTTPMESSAGE_H
