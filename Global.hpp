#ifndef CURL_GLOBAL_HPP
#define CURL_GLOBAL_HPP

#include <curl/curl.h>

namespace Curl {

struct Global {
    const ::CURLcode status;
    inline Global(long = CURL_GLOBAL_ALL);
    inline ~Global();
};

Global::Global(long flags)
  : status(::curl_global_init(flags))
{}

Global::~Global()
{
    ::curl_global_cleanup();
}

} // namespace Curl

#endif // CURL_GLOBAL_HPP
