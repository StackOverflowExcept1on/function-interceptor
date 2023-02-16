#include <module.h>
#include <cstdio>
#include <unistd.h>

int main() {
    for (int i = 0; i < 30; ++i) {
        int ret = exampleFunction(1, 2, 3);
        printf("ret = %d\n", ret);
        sleep(1);
    }
    return 0;
}
