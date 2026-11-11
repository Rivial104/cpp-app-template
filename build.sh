#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"

cmake -B build -DCMAKE_BUILD_TYPE="${BUILD_TYPE:-Debug}"
cmake --build build -j
