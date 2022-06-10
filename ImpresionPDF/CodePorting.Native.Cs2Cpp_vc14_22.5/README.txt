CodePorting.Native Cs2Cpp is a framework capable of translating C# code to C++. The resulting code provides the same API original .Net code had and can run in the native (unmanaged) C++ environment. The CodePorting.Native.Cs2Cpp_vc14_22.5.zip archive contains the Library required by the generated C++ code which is built for the Microsoft Visual C++ compiler. Microsoft Visual Studio 2017 and above are supported in both 32 and 64 bits.

Contents of the archive:
* CodePorting.Native.Cs2Cpp_vc14_22.5/include - Library headers;
* CodePorting.Native.Cs2Cpp_vc14_22.5/lib - Library binaries and CMake target files to be used by dependent (e. g. ported) projects;
* CodePorting.Native.Cs2Cpp_vc14_22.5/licenses - License files for CodePorting.Native Cs2Cpp and 3rd party software it includes;
* CodePorting.Native.Cs2Cpp_vc14_22.5/misc/natvis - NatVis files that make it easy exploring CodePorting.Native Cs2Cpp types in the Microsoft Visual Studio debugger;
* CodePorting.Native.Cs2Cpp_vc14_22.5/misc/qtcreator_debugging_helpers - Debugging helper files that make it easy exploring CodePorting.Native Cs2Cpp types in the Qt Creator debugger;
* CodePorting.Native.Cs2Cpp_vc14_22.5/pch - Precompiled headers that are used to speed up the compilation of the ported projects using the Microsoft Visual C++ compiler;
* CodePorting.Native.Cs2Cpp_vc14_22.5/src/cmake - Cmake modules used by the Library target files;
* CodePorting.Native.Cs2Cpp_vc14_22.5/CodePorting.Native.Cs2Cpp.API.targets - Targets file that can be used to add dependency on the Library to the Microsoft Visual Studio projects;
* CodePorting.Native.Cs2Cpp_vc14_22.5/codeporting.native.cs2cpp-config.cmake - CMake configuration file that can be used to add dependency on the Library to the CMake projects;
* CodePorting.Native.Cs2Cpp_vc14_22.5/codeporting.native.cs2cpp-config-version.cmake - CMake configuration version file that can be used to add dependency on the Library to the CMake projects;
* CodePorting.Native.Cs2Cpp_vc14_22.5/README.txt - This Readme file.

The Library  contains a C++ substitution for .Net classes and some service code. The ported code is ultimately dependent on this component. See https://apireference.codeporting.com/native/cs2cpp for the API reference.

Always make sure that the version of the porter you use to translate your code matches the version of the Library you link the code against. Failing to do so can result in compilation and/or runtime errors, since the API may change between the versions.

______
Links:

* Website: https://www.codeporting.com/
* Product Home: https://products.codeporting.com/native/cs2cpp
* Download: https://downloads.codeporting.com/
* Documentation: https://docs.codeporting.com/native/cs2cpp/
* Free Support Forum: https://forum.codeporting.com/
* Blog: https://blog.codeporting.com/
