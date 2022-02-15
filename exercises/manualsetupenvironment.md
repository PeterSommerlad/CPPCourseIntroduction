# Setup Development Environment

It is recommended that you use the provided Virtual Machine CPPCourse.ova.
This provides a minimal setup with the Cevelop IDE and a Browser with preconfigured Bookmarks for C++.
 
## Installation on Linux

  -  Download Cevelop at https://www.cevelop.com/download/
  -  Unzip it anywhere locally on your filesystem, e.g. in your home directory.
  -  Install a suitable C++ compiler using your package manager.
    -  For C++17 GCC 8.3 or newer is a good choice


## Installation on MacOS

  -  Download Cevelop at https://www.cevelop.com/download/ (or use brew)
  -  Unzip it anywhere locally on your filesystem, e.g. in your home directory.
  -  You might need to install XCode command line tools to obtain a C++ compiler or use homebrew to install gcc-11 to be able to compile C++ programs. Since homebrew will install g++-11 in /opt/homebrew/bin you might need to add that directory to your PATH environment variable. XCode command line tools are available via the default path /usr/bin.


## Cevelop on Windows

(untested)

  -  Download Cevelop at https://www.cevelop.com/download/
  -  Unzip it anywhere locally on your filesystem, e.g. in your home directory.
  -  Download a C++ compiler. Suggestion for Windows is MinGW build of Stephan T. Lavavej as it already contains `boost`: http://nuwen.net/mingw.html
  -  Install MinGW (extract it to the location of your choice)
  -  Check installation by executing `g++ --version` in command prompt. Maybe you need to add the `bin` directory to your `PATH` environment variable.
    -  All dynamically loaded compiler-related libraries must be found for compilation and execution of the compiled programms. It may happen that other paths in the PATH environment variable contain the same libraries. The MinGW path must be entered before them.
  -  In order to let Cevelop recognize your MinGW installation you need to have specific executables in the `bin` directory:
    -  Eclipse CDT/Cevelop (Until version 1.13) looks for an executable with the name `x86_64-w64-mingw32-gcc.exe` in the path variable to determine whether the MinGW compiler is installed. Create a copy the `gcc.exe` named `x86_64-w64-mingw32-gcc.exe` in the `bin` directory of the MinGW installation.
    -  **Note:** In rare cases the specific name above does not work! Try to use `mingw32-gcc.exe` instead.
  - An alternative to MinGW is to install the Linux Subsystem for Windows.


## Using the Virtual Machine

### Installing Virtual Machine

**Note: the virtual machine requires an X86_64 processor and does not work on M1(ARM)-based Macs.**

Download and install VirtualBox, if you do not have a VM supervisor like VMWare already.

Download and install the Virtual Machine (CPPCourse.ova) via the link provided to you

You can either use VMware or '''Virtualbox''' to run the virtual machine. 


#### Virtualbox (Linux, Mac, Windows)
Download and install Virtualbox:

https://www.virtualbox.org/wiki/Downloads or directly via your package manager.

After installation you need to setup the virtual machine. When you started Virtualbox click the "Import Appliance" button, select the appliance file "CPlusPlusHS1614_64.ova" and click "Next". Verify the appliance settings, especially the last entry where your image files are stored and modify if required. Click "Import".

You should be ready now to start with the exercises.

#### Login
Login to the VM using:

*User:* cpp

*Password:* cpppassword

From the desktop menu, select Application->Programming->cevelop

---


