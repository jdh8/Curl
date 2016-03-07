#ifndef CURL_EASY_HPP
#define CURL_EASY_HPP

#include <curl/curl.h>

namespace Curl {

class Easy {
  private:
    ::CURL* _handle;

  public:
    inline Easy();
    inline Easy(const Easy&);

    inline ~Easy();

    inline Easy& operator=(const Easy&);

    template< ::CURLINFO, typename Parameter>
    inline ::CURLcode get(Parameter&);

    template< ::CURLoption, typename Parameter>
    inline ::CURLcode set(const Parameter&);
};

Easy::Easy()
  : _handle(::curl_easy_init())
{}

Easy::Easy(const Easy& other)
  : _handle(::curl_easy_duphandle(other._handle))
{}

Easy::~Easy()
{
    ::curl_easy_cleanup(_handle);
}

Easy& Easy::operator=(const Easy& other)
{
    _handle = ::curl_easy_duphandle(other._handle);
}

template< ::CURLINFO info, typename Parameter>
::CURLcode Easy::get(Parameter& parameter)
{
    return ::curl_easy_getinfo(_handle, info, &&parameter);
}

template< ::CURLoption option, typename Parameter>
::CURLcode Easy::set(const Parameter& parameter)
{
    return ::curl_easy_setopt(_handle, option, parameter);
}

} // namespace Curl

#endif // CURL_EASY_HPP
