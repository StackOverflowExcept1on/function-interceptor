#include <module.h>
#include <cstdio>

int exampleFunction(int a, int b, int c) {
    printf("%s(a=%d, b=%d, c=%d)\n", __FUNCTION__, a, b, c);
    return 42 + a + b + c;
}
