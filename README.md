# Code examples for CMPT 435 Algorithm Analysis & Design

This repository contains various source code and supporting resources for in-class examples from my Algorithm Analysis & Design course. A separate repository contains base code and instructions for lab activities and assignments.

I invite each student to clone this repository locally so that you can build and run the examples yourself. You must have [Visual Studio](https://visualstudio.microsoft.com/vs/community/) to use the Solution and Project files.

Code examples appear primarily in C++, though there are also Haskell implementations for certain algorithms and structures, as well as partial examples in other languages for reference purposes.

Please report any bugs in implementation or instructions to your instructor at Matt.Johnson@marist.edu.

## Working with the C++ language

The C++ language is still among the most widely used programming languages. It is still under development and the language receives ongoing udpates with new features and standard libraries. If you have an interest in IoT/embedded systems or games programming, the ability to code in C++ is a valuable skill.

C++ also supports multiple software development paradigms, from imperative to object-oriented to functional to template meta-programming. It is at once low-level and very high-level, and thus is extremely versatile.

In my opinion, the best freely available reference for the C++ language is the community-sponsored [cppreference.com](https://en.cppreference.com/w/). It is both comprehensive and current, and includes code samples for many of the language features and libraries.

## Prerequisites

### Visual Studio 2019

When installing Visual Studio 2019, be sure to select the **Desktop Development with C++** *workload*. This will pull in a variety of useful individual components, including but not limited to an enhanced build system, profiling tools, and testing frameworks.

If you already have installed Visual Studio 2019, simply run the Visual Studio Installer again and choose the **Modify** option. You will then be able to select additional workloads or components to add to your installation.

### Boost.Test unit testing framework

Most of the class examples rely on the Boost.Test unit testing framework. You must install the necessary library and integrate it with Visual Studio in order to run these examples. Fortunately, Microsoft has made it rather straightforward to install Boost libraries.

1. First, you'll need top make sure you have the "Test Adapter for Boost.Test" component installed in Visual Studio. The previous section of this README covers that.
2. Next, get the vcpkg tool from Microsoft's [vcpkg GitHub repository](https://github.com/Microsoft/vcpkg).
3. Finally, follow the vcpkg repository instructions to install the Boost.Test library and its VS2019 integration.
    - **Important**: The default `boost-test` package is intended for the `x86-windows` architecture. You can choose to build for the `x86` platform in Visual Studio by selecting that option from the corresponding dropdown in the toolbar. If you want to build for your native x64 platform instead, install the `x64-windows` version of the package by using the command `vcpkg/vcpkg install boost-test:x64-windows`. Maybe the safest thing is tp install both versions to ensure compatibility with both platforms so you can build both 32-bit and 64-bit applications as you wish.

References:

- [How to use Boost.Test for C++ in Visual Studio](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-boost-test-for-cpp?view=vs-2019)
- [vcpkg: A C++ package manager for Windows, Linux, and macOS](https://docs.microsoft.com/en-us/cpp/build/vcpkg?view=msvc-160)
