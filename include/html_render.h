//
// Created by PengPremium on 17/1/14.
//

#ifndef WEBPP_HTML_RENDER_H
#define WEBPP_HTML_RENDER_H

#include <string>
#include <fstream>
#include <map>
#include <renderable.h>

namespace webpp
{
    class html_render
    {
     public:
      html_render(std::string template_name);
      void render(const std::map<std::string, std::string>* const parameters = nullptr);
      friend std::ostream& operator<<(std::ostream, const html_render& render);

     private:
      std::ifstream p_file;
      std::string   content;
    };
}
#endif //WEBPP_HTML_RENDER_H
