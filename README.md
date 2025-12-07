# Snake Game

**"Snake"** (aka _"Python"_, _"The Boa Constrictor"_, _"Worm"_) **is a genre of computer games** in which the player controls the "head" of a growing line ("snake") and must not allow it to collide with obstacles, including its "tail".

## Table of Contents

- [Project Status](#project-status)
- [Demo](#demo)
- [Requirements](#requirements)
  - [Linux:](#linux)
    - [Arch](#arch)
    - [Debian/Ubuntu etc.](#debian-ubuntu-etc)
    - [Fedora](#fedora)
    - [Other](#other)
  - [Windows](#windows)
    - [Vcpkg](#vcpkg)
    - [Pdcurses:](#pdcurses)
- [Build && Install](#build-install)
  - [Linux:](#linux)
  - [Windows:](#windows)
- [TODO](#todo)

## Project Status

This project is currently under active development, so most of the functions may not work.

> [!INFO] No tests have been condacted for Windows platform, so if you want to build program anyway, recomended to do it in visual studio, by your own risk

## Demo

https://github.com/user-attachments/assets/6657bf21-5936-465a-80d2-b80b8c5f1aac

## Requirements

### Linux:

You have to have `ncurses.h` library.
You can install it in a lot of distros

#### Arch

```bash
sudo pacman -Syu ncurses
```

#### Debian/Ubuntu etc.

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install libncurses5-dev
```

#### Fedora

```bash
sudo dnf update
sudo dnf install ncurses-devel
```

#### Other

You can search guides for your distro in the internet or you can use official documentation to install it. Also you can build it from scratch

### Windows

#### Vcpkg

```git
git clone https://github.com/Microsoft/vcpkg
.\vcpkg\bootstrap-vcpkg.bat
```

#### Pdcurses:

```bash
.\vcpkg\vcpkg install pdcurses:x64-windows-static
```

## Build && Install

### Linux:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

### Windows:

> [!CAUTION] No tests have been condacted for this platform and there is no ncurses library on win platform(but you can [install](#windows) pdcurses and try to use it)

Recomended to build and compile this project using Visual Studio and on your own risk

<!-- ```bash -->
<!-- mkdir build && cd build -->
<!-- cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -->
<!-- mingw32-make -->
<!-- ``` -->

## TODO

- [x] Finish the raw game (Release tag: 1.0)
- [ ] Make the models better, replace them with ascii characters (Release tag: 2.0)
- [ ] Deal with cmake and write something worthwhile (Release tag: 2.1)
- [ ] Make Colour output (Release tag: 2.2)
- [ ] Make an adapted version for Windows (Release tag: 3.0)
- [ ] Add sounds(when eating, changing direction etc.) (Release tag: 4.0)
