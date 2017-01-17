//
// Created by PengPremium on 17/1/14.
//

#include <regex>
#include <fstream>
#include <iostream>
#include <html_render.h>

namespace webpp
{
    static std::string pattern = "\\$\\{(\\w*)\\}";
    html_render::html_render(std::string template_name)
    {
      p_file.open(template_name, std::ios::in);
    }

    void html_render::render(const std::map<std::string, std::string>* const parameters)
    {
      content = "";
//      std::regex regex(pattern);
//      std::smatch result;
      std::string line;
      while (std::getline(p_file, line))
      {
        content += line;
      }
    }
}

