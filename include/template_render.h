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
    class template_render
    {
     public:
      template_render() {}
//      template_render(template_render& tr)
//      {
//        p_file = std::move(tr.p_file);
//        variables = tr.variables;
//      }
      template_render(std::string template_name);

      void set_variable(const std::string& var_name,  std::shared_ptr<renderable> var_value);
      const std::shared_ptr<renderable> get_variable(const std::string var_name) const;
      void remove_variable(const std::string var_name);

      friend std::ostream &operator<<(std::ostream &stream, const template_render &render);

     private:
      mutable std::ifstream p_file;

      std::map<std::string, std::shared_ptr<renderable> > variables;
    };
}
#endif //WEBPP_HTML_RENDER_H
