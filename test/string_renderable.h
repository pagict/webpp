//
// Created by PengPremium on 17/1/15.
//

#ifndef WEBPP_STRING_RENDERABLE_H
#define WEBPP_STRING_RENDERABLE_H

#include <renderable.h>
    class string_renderable : public webpp::renderable, public std::string
    {
     public:
      string_renderable(const std::string& string)
      : std::string(string)
      {}

      std::string get_render_string() {
        return *this;
      }
    };

#endif //WEBPP_STRING_RENDERABLE_H
