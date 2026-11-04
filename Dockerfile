# Build the C÷ command-line compiler.
FROM ubuntu:24.04 AS build

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && apt-get install -y --no-install-recommends build-essential cmake ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . .
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF \
    && cmake --build build --config Release --parallel \
    && cmake --install build --prefix /usr/local

# The current native preview invokes a host C++20 compiler when building .cdiv files,
# so keep that toolchain available in the runtime image as well.
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && apt-get install -y --no-install-recommends g++ ca-certificates \
    && rm -rf /var/lib/apt/lists/*

COPY --from=build /usr/local/bin/cdiv /usr/local/bin/cdiv
WORKDIR /workspace
ENTRYPOINT ["cdiv"]
