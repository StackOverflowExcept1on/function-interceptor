### function-interceptor

This project demonstrates how to hook functions through the [funchook](https://github.com/kubo/funchook) library

### Requirements

- g++ compiler
- cmake
- python3
- frida: https://frida.re

### Preparing

```bash
# install dependencies
pip install frida

# change the ptrace_scope for frida
sudo sysctl kernel.yama.ptrace_scope=0

# build c++ project
./build.sh
```

### Running

```bash
# run program (it is assumed that in different terminals)
LD_LIBRARY_PATH=./build/bin ./build/bin/program

# attach `./build/bin/libhook.so` to `$(pidof program)`
./scripts/loader.py $(pidof program) ./build/bin/libhook.so
```

```
exampleFunction(a=1, b=2, c=3)
ret = 48

handle = 0x7f79317921e0
exampleFunction_original = 0x7f793178e120

exampleFunction(a=1, b=2, c=3)
[+] org ret = 48
[+] exampleFunction_hook(a=1, b=2, c=3)
ret = 42
```
