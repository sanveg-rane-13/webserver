# creates new stage from existing Docker Image
FROM ubuntu:22.10
LABEL Description="Bas environment with cmake"

ARG CMAKE_VERSION=3.25.1
ARG NUM_JOBS=8

# executes a command in the Image
RUN apt-get update && \
    apt-get -y --no-install-recommends install \
        build-essential \
        cmake \
        clang \
        libboost-all-dev \
        valgrind \
        vim \
        wget && \
    apt-get clean
