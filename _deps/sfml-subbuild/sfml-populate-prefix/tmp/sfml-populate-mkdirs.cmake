# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-src"
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-build"
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/connorwhisman/Documents/Dev/Self-Dev/CPP Test/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
