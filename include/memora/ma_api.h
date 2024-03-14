#ifndef MEMORA_MAAPI_H
#define MEMORA_MAAPI_H

#ifdef MA_SHARED
#if defined _WIN32 || defined __CYGWIN__
    #ifdef memora_EXPORTS
      #ifdef __GNUC__
        #define MA_API __attribute__ ((dllexport))
      #else
        #define MA_API __declspec(dllexport)
      #endif
    #else
      #ifdef __GNUC__
        #define MA_API __attribute__ ((dllimport))
      #else
        #define MA_API __declspec(dllimport)
      #endif
    #endif
  #else
    #if __GNUC__ >= 4
      #define MA_API __attribute__ ((visibility ("default")))
    #else
      #define MA_API
    #endif
  #endif
#else
#define MA_API
#endif

#endif //MEMORA_MAAPI_H
