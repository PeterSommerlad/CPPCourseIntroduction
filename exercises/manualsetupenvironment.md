# Setup Development Environment

It is recommended that you use the provided Virtual Machine CPPCourse26.ova and run it in VirtualBox (>7.2).
This provides a Linux setup with the Cevelop IDE and a Vivaldi Browser with preconfigured Bookmarks for C++.
The download link is provided to you via email.
 
## Using the Virtual Machine

### Installing Virtual Machine

**Note: the virtual machine requires an X86_64 processor and does not work (well) on M1(ARM)-based Macs.**

Download and install VirtualBox, if you do not have a VM supervisor like VMWare already.

Download and install the Virtual Machine ( CPPCourse26.ova 10GB) via the link provided to you.

You can either use VMware or '''Virtualbox''' to run the virtual machine. 

For an ARM-based MacOS computer (M1, M2...), it seems best to use a setup provided by the training center.

If you are brave and know your way around MacOS intricacies, you can try to use the VM using UTM provided via the link, or you can try to install a beta version of Cevelop compiled for ARM on MacOS.
Ask for the link. Note, this version of Cevelop requires a setup with an older Java VM and thus might not work without convincing your MacOS that it is safe to run (settings and acknowledgemen). It works well on my M1 Mac, but it was also compiled there.

If you are very patient or have a very fast ARM-based Mac, you can try the UTM emulator and rund the VM through this. However, the experience might be unacceptably slow to be useful.


#### Virtualbox (Linux, Mac(Intel), Windows)

Download and install Virtualbox (>7.2):

https://www.virtualbox.org/wiki/Downloads or directly via your package manager.

After installation you need to setup the virtual machine. When you started Virtualbox click the "Import Appliance" button, select the appliance file "CPPCourse26.ova" and click "Next". Verify the appliance settings, especially the last entry where your image files are stored and modify if required. Click "Import".

You should be ready now to start with the exercises.


#### Login
Login to the VM using:

*User:* cpp

*Password:* cpppassword

From the desktop (menu), select Application->Programming->cevelop

----

# The following mechanisms are no longer guaranteed to work

Cevelop's base Eclipse CDT and Java evolved over time and Cevelop is no longer maintained. 
However, for this training, it provides unique features not available in other more current IDEs.
You might need to install an older Java version than the most current one to make Cevelop work.


## Manual Installation on Linux

  -  Download Cevelop at https://www.cevelop.com/download/
  -  Unzip it anywhere locally on your filesystem, e.g. in your home directory.
  -  Install a suitable C++ compiler (most recent) using your package manager.


## Installation on MacOS

Note: as of today, the release Cevelop does not yet run on the newer M(ARM - aarch64) Macs (see below).

  -  Download Cevelop at https://www.cevelop.com/download/ (or use brew)
  -  Unzip it anywhere locally on your filesystem, e.g. in your home directory.
  -  You might need to install XCode command line tools to obtain a C++ compiler or use homebrew to install gcc-14 to be able to compile C++ programs. Since homebrew will install g++-14 in /opt/homebrew/bin you might need to add that directory to your PATH environment variable. XCode command line tools are available via the default path /usr/bin.


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


