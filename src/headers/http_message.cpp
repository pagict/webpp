//
// Created by PengPremium on 17/1/8.
//
#include <headers/http_message.h>
#include <headers/http_headers.h>

namespace webpp
{
    http_message::http_message()
    {
      headers = default_http_headers;
    }

    void http_message::setHeader(const string &key, const string &value)
    {
      auto it = headers.find(key);
      if (it == headers.end()) {
        headers.emplace(key, value);
      }
      it->second = value;
    }

    void http_message::setPayload(const string &payload)
    {
      this->payload = payload;
    }

    std::ostream &operator<<(std::ostream &stream, webpp::http_message const &msg)
    {
      for (auto it = msg.headers.cbegin(); it != msg.headers.cend(); it++) {
        stream << it->first << ": " << it->second << "\r\n";
      }
      stream << "\r\n";
      stream << msg.payload;
      return stream;
    }
}