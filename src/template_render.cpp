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

    void template_render::set_variable(const std::string &var_name, std::shared_ptr<renderable> obj)
    {
      variables.emplace(var_name, obj);
    }

    const std::shared_ptr<renderable> template_render::get_variable(const std::string var_name) const
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

      std::regex ex(pattern);
      std::smatch result;


      std::string line;
      while (std::getline(render.p_file, line))
      {
        bool need_replace = std::regex_search(line, result, ex);
        long idx = -1;
        long length = -1;
        if (need_replace)
        {
          idx = result.position();
          length = result.length();

          stringbuf.sputn(line.substr(0, idx).c_str(), idx);

          std::string key = result[1];
          std::shared_ptr<renderable> v = render.variables.at(key);
          std::string description = v->get_render_string();
          stringbuf.sputn(description.c_str(), description.length());
          stringbuf.sputn(line.substr(idx + length).c_str(), line.length() - idx - length);

        } else
        {
          stringbuf.sputn(line.c_str(), line.length());
        }
      }

      stream << stringbuf.str();
      return stream;
    }
}

