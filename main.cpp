#include <iostream>
//#include <fcgi_stdio.h>
#include <fcgio.h>

using namespace std;
int main()
{
  streambuf *in_streambuf = cin.rdbuf();
  streambuf *out_streambuf = cout.rdbuf();
  streambuf *err_streambuf = cerr.rdbuf();

  FCGX_Request request;
  FCGX_Init();
  FCGX_InitRequest(&request, 0, 0);
  while (FCGX_Accept_r(&request) == 0) {
    fcgi_streambuf cin_fcgi_streambuf(request.in);
    fcgi_streambuf cout_fcgi_streambuf(request.out);
    fcgi_streambuf cerr_fcgi_streambuf(request.err);

    cin.rdbuf(&cin_fcgi_streambuf);
    cout.rdbuf(&cout_fcgi_streambuf);
    cerr.rdbuf(&cerr_fcgi_streambuf);

    cout << "Content-Type: text/html\r\n"
         << "\r\n"
         << "<html>\n"
         << " <head>\n"
         << "   <title>Hello Title</title>\n"
         << " </head>\n"
         << " <body>\n"
         << "   <h1>Hello body, hot body</h1>\n"
         << " </body>\n"
         << "</html>\n";
  }

  cin.rdbuf(in_streambuf);
  cout.rdbuf(out_streambuf);
  cerr.rdbuf(err_streambuf);
  return 0;
}