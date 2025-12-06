# Snake Game

**"Snake"** (aka _"Python"_, _"The Boa Constrictor"_, _"Worm"_) **is a genre of computer games** in which the player controls the "head" of a growing line ("snake") and must not allow it to collide with obstacles, including its "tail".

# Table of Contents

- [Project Status](#project-status)
- [⚠️Requirements](#⚠️requirements)
  - [🐧Linux:](#🐧linux)
    - [Arch](#arch)
    - [Debian/Ubuntu etc.](#debian-ubuntu-etc)
    - [Fedora](#fedora)
    - [Other](#other)
  - [🪟Windows](#🪟windows)
    - [Vcpkg](#vcpkg)
    - [Pdcurses:](#pdcurses)
- [🛠️Build && Install](#🛠️build-install)
  - [🐧Linux:](#🐧linux)
  - [🪟Windows:](#🪟windows)
- [☑️TODO](#☑️todo)

# Project Status

This project is currently under active development, so most of the functions may not work.

# ⚠️Requirements

## 🐧Linux:

You have to have `ncurses.h` library.
You can install it in a lot of distros

### Arch

```bash
sudo pacman -Syu ncurses
```

### Debian/Ubuntu etc.

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install libncurses5-dev
```

### Fedora

```bash
sudo dnf update
sudo dnf install ncurses-devel
```

### Other

You can search guides for your distro in the internet or you can use official documentation to install it. Also you can build it from scratch

## 🪟Windows

### Vcpkg

```git
git clone https://github.com/Microsoft/vcpkg
.\vcpkg\bootstrap-vcpkg.bat
```

### Pdcurses:

```bash
.\vcpkg\vcpkg install pdcurses:x64-windows-static
```

# 🛠️Build && Install

## 🐧Linux:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

## 🪟Windows:

> ! CAUTION: No tests have been condacted for this platform and there is no ncurses library on win platform

```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
mingw32-make
```

# ☑️TODO

If ypu want to know what i have to do, then read [TODO.md](./TODO.md)
