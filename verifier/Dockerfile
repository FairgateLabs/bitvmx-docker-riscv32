FROM riscv32:latest

WORKDIR /

RUN apt-get -y update
RUN apt-get upgrade --yes 
RUN apt-get -y install clang 

RUN cd /src && \ 
    git clone -v --recursive https://github.com/FairgateLabs/bitvmx-zk-verifier --branch custom_flags

RUN cp -r /riscv32/riscv32-unknown-elf/include/* /src/bitvmx-zk-verifier/mcl/include/  




