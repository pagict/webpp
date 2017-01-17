cmake_minimum_required(VERSION 3.7)
project(webpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES test/main.cpp include/headers/http_message.h src/headers/http_message.cpp src/webpp_application.cpp include/webpp_application.h src/html_render.cpp include/html_render.h include/renderable.h test/string_renderable.h include/path_handler.h test/root_handler.cpp test/root_handler.h)
add_executable(webpp ${SOURCE_FILES})
target_link_libraries(webpp fcgi fcgi++)
