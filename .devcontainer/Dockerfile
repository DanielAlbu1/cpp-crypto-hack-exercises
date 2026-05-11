FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get install -y --no-install-recommends \
        ninja-build \
        cmake \
        gdb \
        lldb \
        valgrind \
        clangd \
        clang-format \
        pkg-config \
        git \
        curl \
        wget \
        unzip \
        xz-utils \
        libssl-dev \
        libgmp-dev \
        libboost-all-dev \
        libsodium-dev \
    && rm -rf /var/lib/apt/lists/*
