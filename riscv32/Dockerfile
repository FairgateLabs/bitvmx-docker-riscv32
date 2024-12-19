FROM ubuntu:jammy-20240405

RUN apt-get -y update
RUN apt-get upgrade --yes 
RUN apt-get -y install git \ 
    autoconf=2.71-2 \
    automake=1:1.16.5-1.3 \
    autotools-dev=20220109.1 \
    curl \
    libmpc-dev=1.2.1-2build1  \
    libmpfr-dev=4.1.0-3build3 \
    libgmp-dev=2:6.2.1+dfsg-3ubuntu1 \
    gawk=1:5.1.0-1ubuntu0.1 \
    build-essential=12.9ubuntu3 \
    bison=2:3.8.2+dfsg-1build1 \
    flex=2.6.4-8build2 \
    texinfo=6.8-4build1 \
    gperf=3.1-1build1 \
    libtool=2.4.6-15build2 \
    patchutils=0.4.2-1build2  \
    bc=1.07.1-3build1 \
    zlib1g-dev=1:1.2.11.dfsg-2ubuntu9.2  \
    libexpat-dev

RUN git config --global http.sslverify false

RUN mkdir /src && \
  cd /src && \
  git clone https://github.com/riscv/riscv-gnu-toolchain --branch 2024.09.03

RUN cd /src/riscv-gnu-toolchain/ && \
  ./configure --prefix=/riscv32 --with-arch=rv32im --with-abi=ilp32 && \
  make -j 8 


#qemu reqs
RUN apt-get -y install dos2unix python3 pkg-config libglib2.0-dev libpixman-1-dev vim python3-pip ninja-build
RUN pip install tomli

RUN cd /src && \
  git clone https://git.qemu.org/git/qemu.git && \
  cd qemu && \
  ./configure --prefix=/riscv32 --static --disable-system --target-list=riscv32-linux-user && \
  make -j 8 && \
  make install

ENV PATH=/riscv32/bin:$PATH

ENV CC=riscv32-unknown-elf-gcc
ENV CXX=riscv32-unknown-elf-c++
ENV CPP=riscv32-unknown-elf-cpp
ENV AS=riscv32-unknown-elf-as
ENV LD=riscv32-unknown-elf-ld
ENV AR=riscv32-unknown-elf-ar
ENV DUMP=riscv32-unknown-elf-objdump
ENV RANLIB=riscv32-unknown-elf-ranlib
ENV HOST=riscv32-unknown-elf
ENV QEMU=qemu-riscv32

WORKDIR /data

# Default command
CMD ["/bin/bash"]