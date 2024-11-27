# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/saucesaft/Developer/JO1_Embedded/CM4"
  "/Users/saucesaft/Developer/JO1_Embedded/CM4/build"
  "/Users/saucesaft/Developer/JO1_Embedded/CM4"
  "/Users/saucesaft/Developer/JO1_Embedded/CM4/tmp"
  "/Users/saucesaft/Developer/JO1_Embedded/CM4/src/JO1_Embedded_CM4-stamp"
  "/Users/saucesaft/Developer/JO1_Embedded/CM4/src"
  "/Users/saucesaft/Developer/JO1_Embedded/CM4/src/JO1_Embedded_CM4-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/saucesaft/Developer/JO1_Embedded/CM4/src/JO1_Embedded_CM4-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/saucesaft/Developer/JO1_Embedded/CM4/src/JO1_Embedded_CM4-stamp${cfgdir}") # cfgdir has leading slash
endif()
