cmake_minimum_required(VERSION 3.7)
project(webpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES test/main.cpp include/headers/http_message.h src/headers/http_response.cpp include/headers/http_response.h src/headers/http_message.cpp src/webpp_application.cpp include/webpp_application.h include/headers/http_headers.h src/headers/http_request.cpp include/headers/http_request.h src/html_render.cpp include/html_render.h)
add_executable(webpp ${SOURCE_FILES})
target_link_libraries(webpp fcgi fcgi++)
