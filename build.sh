#!/usr/bin/env bash
# usage: ./build.sh [Debug|Release] [--clean] [--test]
set -euo pipefail
cd "$(dirname "$0")"

BUILD_TYPE="Debug"
CLEAN=0
TEST=0

for arg in "$@"; do
    case "$arg" in
        Debug|Release|RelWithDebInfo|MinSizeRel) BUILD_TYPE="$arg" ;;
        --clean) CLEAN=1 ;;
        --test)  TEST=1 ;;
        *) echo "Unknown argument: $arg"; echo "Usage: $0 [Debug|Release] [--clean] [--test]"; exit 1 ;;
    esac
done

if [[ $CLEAN -eq 1 ]]; then
    rm -rf build bin
fi

GENERATOR=()
command -v ninja >/dev/null && GENERATOR=(-G Ninja)

if [[ -f build/CMakeCache.txt ]]; then
    GENERATOR=()
fi

cmake -S . -B build "${GENERATOR[@]}" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
cmake --build build -j

if [[ $TEST -eq 1 ]]; then
    ctest --test-dir build --output-on-failure
fi
