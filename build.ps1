$ErrorActionPreference = "Stop"

# Define paths to tools (as found on the system)
$NinjaPath = "$env:LOCALAPPDATA\Microsoft\WinGet\Links\ninja.exe"
$GccPath = "$env:LOCALAPPDATA\Microsoft\WinGet\Packages\BrechtSanders.WinLibs.MCF.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin\gcc.exe"
$GppPath = "$env:LOCALAPPDATA\Microsoft\WinGet\Packages\BrechtSanders.WinLibs.MCF.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin\g++.exe"

# Check if tools exist
if (-not (Test-Path $NinjaPath)) { Write-Host "Error: Ninja not found at $NinjaPath"; exit 1 }
if (-not (Test-Path $GccPath)) { Write-Host "Error: GCC not found at $GccPath"; exit 1 }

# Create build directory
if (-not (Test-Path "build_ninja")) {
    New-Item -ItemType Directory -Force -Path "build_ninja" | Out-Null
}

# Configure CMake
Write-Host "Configuring project..."
cmake -G Ninja `
    -DCMAKE_MAKE_PROGRAM="$NinjaPath" `
    -DCMAKE_C_COMPILER="$GccPath" `
    -DCMAKE_CXX_COMPILER="$GppPath" `
    -B build_ninja

# Build
Write-Host "Building project..."
cmake --build build_ninja

# Run
Write-Host "Running StoreTUI..."
.\build_ninja\StoreTUI.exe
