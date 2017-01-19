//
// Created by PengPremium on 17/1/14.
//

#ifndef WEBPP_WEBPPAPPLICATION_H
#define WEBPP_WEBPPAPPLICATION_H

#include <vector>
#include <path_handler.h>

namespace webpp
{
    class webpp_application {
     public:
      webpp_application();
      ~webpp_application();
      void start();

      void register_handler(std::shared_ptr<path_handler>);

     private:
      std::vector<std::shared_ptr<path_handler>> handlers;
    };
}

#endif //WEBPP_WEBPPAPPLICATION_H
