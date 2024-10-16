# Docker RISCV32 Build Enviornment

This repo contains the necessary files to create a program that can be run in the BitVMX-CPU.
To simplify the environment and the build tools required to build for RISCV-32 architecture some Dockerfiles and scripts are provided.


## Structure

- **riscv32**: The base Dockerfile to build the [riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain) toolchain that is used to compile .C programs into RISCV32 compatible .elf files for the BitVMX-CPU and a build script to help building the .C files. Also to give support for Mac Docker.arch file is provided which gets an unofficial archlinux docker image.
- **src**: Some C samples alongside `emulator.h` and `entrypoint.s` which are necessary dependencies.
- **linker**: `link.ld` that defines the memory layout.
- **compliance**: Another Dockerfile which builds on top of riscv32 image, and allows to compile the riscv32i (and m extension) files needed to run the compliance tests of the emulator.
- **verifier**: Dockerfile which also builds on top of riscv32 image and allows to compile a groth16 verifier.

## Helper Scripts

On the root folder there are some help scripts used to build the images and compile the programs.

### Building The Images
To build the images run the corresponding script for Win,Linux,Mac (`docker-build.bat`, `docker-build.sh` or `docker-build-mac.sh` )


### Compiling the Programs
To compile a .C file `docker-run.bat` or `docker-run.sh` can be used:

Sample files:  
`docker-run.bat riscv32 riscv32/build.sh src/hello-world.c --with-mul`

Compliance files:  
`docker-run.bat compliance compliance/build_all.sh`

ZKP groth16 Verifier
`docker-run.bat verifier verifier/build.sh --with-mul`


## Inside the Docker Container

To build other files this information might be helpful:

#### build.sh
Use `build.sh FILE_NAME.c` to generate the .elf file. (It might be necessary to `chmod +x` the file to execute it)

Before creating your own `.c` file please take a look at some of the examples: `hello-world.c` `plain.c` or `test_input.c` and also the build script (`build.sh`) itself.

Some requirements are:

The `.c` file needs to include at least this part:
```
    #include "emulator.h"
    #include <stdint.h>

    int main(int x) {
        return 0;
    }
```

And the file needs to be linked using `linkd.ld` file which describes the memory sections of the files and using `entrypoint.s` which defines the real entrypoint and calls main.
