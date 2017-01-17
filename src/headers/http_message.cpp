//
// Created by PengPremium on 17/1/8.
//
#include <headers/http_message.h>

namespace webpp
{
    http_message::http_message()
    {
      headers = default_http_headers;
    }

    void http_message::set_header(const string &key, const string &value)
    {
      auto it = headers.find(key);
      if (it == headers.end()) {
        headers.emplace(key, value);
      }
      it->second = value;
    }

    void http_message::set_payload(const string &payload)
    {
      this->payload = payload;
    }

    const string& http_message::get_header(const string &key) const
    {
      return headers.at(key);
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