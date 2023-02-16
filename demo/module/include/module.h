#ifndef MODULE_H
#define MODULE_H

#if defined(WIN32)
#define DLL_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define DLL_EXPORT __attribute__((visibility("default")))
#endif

extern "C" DLL_EXPORT int exampleFunction(int a, int b, int c);

#endif //MODULE_H
