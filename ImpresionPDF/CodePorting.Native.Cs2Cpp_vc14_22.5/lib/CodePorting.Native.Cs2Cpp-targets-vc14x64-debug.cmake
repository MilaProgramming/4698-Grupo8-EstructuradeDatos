#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Aspose::CodePorting.Native.Cs2Cpp" for configuration "Debug"
set_property(TARGET Aspose::CodePorting.Native.Cs2Cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Aspose::CodePorting.Native.Cs2Cpp PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/aspose_cpp_vc14x64d.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/aspose_cpp_vc14x64d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Aspose::CodePorting.Native.Cs2Cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_Aspose::CodePorting.Native.Cs2Cpp "${_IMPORT_PREFIX}/lib/aspose_cpp_vc14x64d.lib" "${_IMPORT_PREFIX}/lib/aspose_cpp_vc14x64d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
