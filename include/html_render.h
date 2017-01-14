//
// Created by PengPremium on 17/1/14.
//

#ifndef WEBPP_HTML_RENDER_H
#define WEBPP_HTML_RENDER_H

#include <string>
#include <fstream>
namespace webpp
{
    class html_render
    {
     public:
      html_render(std::string template_name);
      void render(int param_num, ...);
      friend std::ostream& operator<<(std::ostream, const html_render& render);

     private:
      std::ifstream p_file;
      std::string   content;
    };
}
#endif //WEBPP_HTML_RENDER_H
