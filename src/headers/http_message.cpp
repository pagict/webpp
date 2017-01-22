//
// Created by PengPremium on 17/1/8.
//
#include <headers/http_message.h>
#include <sstream>

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

//    void http_message::set_payload(const string &payload)
//    {
//      this->payload = payload;
//    }

    const string& http_message::get_header(const string &key) const
    {
      return headers.at(key);
    }

    std::ostream &operator<<(std::ostream &stream, const webpp::http_message &msg)
    {
      stream << msg.headers_string();
      return stream;
    }

    string http_message::headers_string() const
    {
      stringbuf buf;
      for (auto it = this->headers.cbegin(); it != this->headers.cend(); it++)
      {
        buf.sputn(it->first.c_str(), it->first.length());
        buf.sputn(": ", 2);
        buf.sputn(it->second.c_str(), it->second.length());
        buf.sputn("\r\n", 2);
      }

      buf.sputn("\r\n", 2);
      return buf.str();
    }

    http_request::http_request(char **const envp){
      const string EQUAL_SIGN = "=";
      char** env = envp;
      while (*env)
      {
        string kv_pair(*env);
        size_t equal_idx = kv_pair.find(EQUAL_SIGN);
        if (equal_idx != string::npos)
        {
          this->set_header(kv_pair.substr(0, equal_idx), kv_pair.substr(equal_idx+1));
        }

        env++;
      }
    }

    std::ostream& operator<<(std::ostream &stream, const http_response& response)
    {
      stream << response.headers_string();
      stream << response.render;
      return stream;
    }
}