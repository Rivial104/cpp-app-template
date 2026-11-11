#!/usr/bin/env bash
# Usage: ./run.sh [-c] [-b] [-- app args...]
#   -c  clean (remove build directory)
#   -b  build
#   no flags = only run
set -euo pipefail
cd "$(dirname "$0")"

clean=0
build=0

while getopts ":cbh" opt; do
    case "$opt" in
        c) clean=1 ;;
        b) build=1 ;;
        h) echo "Usage: $0 [-c] [-b] [-- app args...]"; exit 0 ;;
        \?) echo "Unknown option: -$OPTARG" >&2; exit 1 ;;
    esac
done
shift $((OPTIND - 1))

if (( clean )); then
    rm -rf build
fi

if (( build )); then
    ./build.sh
fi

if [[ ! -x ./build/App/App ]]; then
    echo "Binary ./build/App/App not found. Run with -b to build." >&2
    exit 1
fi

exec ./build/App/App "$@"
