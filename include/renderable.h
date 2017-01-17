//
// Created by PengPremium on 17/1/15.
//

#ifndef WEBPP_RENDERABLE_H
#define WEBPP_RENDERABLE_H

#include <string>
namespace webpp
{
    class renderable
    {
     public:
      virtual std::string get_render_string() = 0;
    };
}
#endif //WEBPP_RENDERABLE_H
