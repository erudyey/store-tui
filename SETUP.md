# Project Setup Guide

This guide covers how to set up the development environment for the Store TUI project on Windows, macOS, and Linux.

## Tools Installed (Windows)
For this project on Windows, I installed the following tools using `winget`:
- **CMake** (`Kitware.CMake`): Build system generator.
- **Ninja** (`Ninja-build.Ninja`): Fast build tool used by CMake.
- **MinGW-w64 GCC** (`BrechtSanders.WinLibs.MCF.UCRT`): C++ Compiler.

## Prerequisites

### Windows
1.  **Install CMake**:
    ```powershell
    winget install -e --id Kitware.CMake
    ```
2.  **Install Ninja** (Optional but recommended):
    ```powershell
    winget install -e --id Ninja-build.Ninja
    ```
3.  **Install C++ Compiler (MinGW GCC)**:
    ```powershell
    winget install -e --id BrechtSanders.WinLibs.MCF.UCRT
    ```
    *Note: You may need to restart your terminal after installation.*

### macOS
1.  **Install Xcode Command Line Tools** (includes Clang):
    ```bash
    xcode-select --install
    ```
2.  **Install CMake**:
    ```bash
    brew install cmake
    ```

### Linux (Ubuntu/Debian)
1.  **Install GCC and CMake**:
    ```bash
    sudo apt update
    sudo apt install build-essential cmake
    ```

## Building the Project

### Windows (Recommended)
I have provided a PowerShell script to automatically configure and build the project using the installed tools.

1.  Open PowerShell in the project directory.
2.  Run the build script:
    ```powershell
    .\build.ps1
    ```
    This script will:
    - Locate the Ninja and GCC tools installed via Winget.
    - Configure the project using CMake.
    - Build the executable.
    - Run the application.

### macOS / Linux
1.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```
2.  Generate build files:
    ```bash
    cmake ..
    ```
3.  Compile:
    ```bash
    cmake --build .
    ```
4.  Run:
    ```bash
    ./StoreTUI
    ```

## Troubleshooting (Windows)
If you prefer to run CMake manually on Windows or if the script fails, you need to specify the full paths to the compilers installed by Winget.

```powershell
# Example Manual Build Command
cmake -G Ninja `
    -DCMAKE_MAKE_PROGRAM="$env:LOCALAPPDATA\Microsoft\WinGet\Links\ninja.exe" `
    -DCMAKE_C_COMPILER="$env:LOCALAPPDATA\Microsoft\WinGet\Packages\BrechtSanders.WinLibs.MCF.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin\gcc.exe" `
    -DCMAKE_CXX_COMPILER="$env:LOCALAPPDATA\Microsoft\WinGet\Packages\BrechtSanders.WinLibs.MCF.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin\g++.exe" `
    -B build_ninja

cmake --build build_ninja
```
