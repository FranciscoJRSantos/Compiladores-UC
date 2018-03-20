FROM debian:jessie

RUN echo "deb http://ftp.debian.org/debian jessie-backports main" >> /etc/apt/sources.list
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      llvm clang flex bison vim libc6-dbg gdb valgrind zip

COPY . /comp
WORKDIR /comp
