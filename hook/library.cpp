#include <funchook.h>

#include <cstdio>
#include <dlfcn.h>

#if defined(WIN32)
#define DLL_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define DLL_EXPORT __attribute__((visibility("default")))
#endif

int exampleFunction_hook(int a, int b, int c) {
    printf("[+] %s(a=%d, b=%d, c=%d)\n", __FUNCTION__, a, b, c);
    return 42;
}

extern "C" DLL_EXPORT void onStartup() {
    funchook_t *funchook = funchook_create();
    int ret;

    void *handle = dlopen("libmodule.so", RTLD_NOW);
    printf("handle = %p\n", handle);
    void *targetFunction = dlsym(handle, "exampleFunction");
    printf("targetFunction = %p\n", targetFunction);

    ret = funchook_prepare(funchook, (void **) &targetFunction, (void *) exampleFunction_hook);
    if (ret != 0) {
        printf("[-] funchook_prepare failed, ret = %d\n", ret);
        return;
    }

    ret = funchook_install(funchook, 0);
    if (ret != 0) {
        printf("[-] funchook_install failed, ret = %d\n", ret);
        return;
    }
}
