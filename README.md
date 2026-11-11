# cpp-app-template -- Project Overview

# Prerequesties

On WSL is it required to have `wayland` and `libX` installed.
When code is not compiling do:

```bash
sudo apt install libxkbcommon-dev libwayland-dev wayland-protocols \
    libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libx11-dev \
    libgl1-mesa-dev pkg-config
```

Additionally, we use C++23 feauters, so gcc-14 is required:

```bash
sudo apt install g++-14
```

# Build and run

Just use `./run.sh` script