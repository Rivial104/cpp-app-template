#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"

cmake -B build \
    -DCMAKE_BUILD_TYPE="${BUILD_TYPE:-Debug}" \
    -DCMAKE_C_COMPILER=gcc-14 \
    -DCMAKE_CXX_COMPILER=g++-14
cmake --build build -j
