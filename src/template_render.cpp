//
// Created by PengPremium on 17/1/14.
//

#include <regex>
#include <fstream>
#include <iostream>
#include <template_render.h>
#include <sstream>

namespace webpp
{
    static std::string pattern = "\\$\\{(\\w*)\\}";
    template_render::template_render(std::string template_name)
    {
      p_file.open(template_name, std::ios::in);
    }

    void template_render::set_variable(const std::string &var_name, renderable &obj)
    {
      variables.emplace(var_name, obj);
    }

    const renderable& template_render::get_variable(const std::string var_name) const
    {
      return variables.at(var_name);
    }

    void template_render::remove_variable(const std::string var_name)
    {
      variables.erase(var_name);
    }

//    void template_render::render(const std::map<std::string, std::string>* const parameters)
//    {
//      content = "";
////      std::regex regex(pattern);
////      std::smatch result;
//      std::string line;
//      while (std::getline(p_file, line))
//      {
//        content += line;
//      }
//    }

    std::ostream& operator<<(std::ostream& stream, const template_render &render)
    {
      render.p_file.seekg(0);

      std::stringbuf stringbuf;

      std::string line;
      while (std::getline(render.p_file, line)) {
        stringbuf.sputn(line.c_str(), line.length());
      }

      stream << stringbuf.str();
      return stream;
    }
}

