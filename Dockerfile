FROM ubuntu:24.04

WORKDIR /cpp_playground

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y && apt-get install -y \
  g++ \
  cmake \
  ninja-build