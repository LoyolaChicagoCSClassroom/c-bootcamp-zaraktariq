# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-src"
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-build"
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix"
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspace/c-bootcamp-zaraktariq/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
