# 
# Project: KeenCore
# License: GNU General Public License v2.0 or later (GPL-2.0+)
# This file is part of KeenCore.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Originally based on MaNGOS (Massive Network Game Object Server)
# Copyright (C) 2005-2025 MaNGOS project <https://getmangos.eu>
#

cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

# Project definition
project(KeenCore)

# Add CMake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set required policies
cmake_policy(SET CMP0028 NEW)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0042 NEW)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0063 NEW)

# Set C++ and C standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable folder structure in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Define build options
option(BUILD_WORLDSERVER "Build the main server" ON)
option(BUILD_AUTHSERVER "Build the login server" ON)
option(BUILD_TOOLS "Build the map/vmap/mmap extractors" ON)
option(USE_STORMLIB "Use StormLib for reading MPQs" ON)
option(SCRIPT_LIB_ELUNA "Compile with support for Eluna scripts" ON)
option(SCRIPT_LIB_SD3 "Compile with support for ScriptDev3 scripts" ON)
option(PLAYERBOTS "Enable Player Bots" OFF)
option(SOAP "Enable remote access via SOAP" OFF)
option(PCH "Enable precompiled headers" ON)
option(DEBUG "Enable debug build (only on non-IDE environments)" OFF)

# Set default install prefix if not specified
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Default install directory" FORCE)
endif()

# Choose build type (Debug or Release)
if(DEBUG)
  set(CMAKE_BUILD_TYPE Debug)
else()
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set directories based on the operating system
if(UNIX)
    set(BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin")
    set(CONF_INSTALL_DIR "${CONF_INSTALL_DIR}" CACHE PATH "Configuration install directory")
    if(NOT CONF_INSTALL_DIR)
        set(CONF_INSTALL_DIR "../etc")
    endif()
else()
    set(BIN_DIR "${CMAKE_INSTALL_PREFIX}")
    set(CONF_INSTALL_DIR "." CACHE PATH "Configuration install directory")
endif()

# Ensure Git is found if necessary
if(NOT WITHOUT_GIT)
  find_package(Git)
endif()

# Find required packages
find_package(Threads REQUIRED)
find_package(MySQL REQUIRED)
find_package(DL REQUIRED)
find_package(ZLIB QUIET)
find_package(BZip2 QUIET)
find_package(OpenSSL REQUIRED)

# Include additional CMake files
include(${CMAKE_SOURCE_DIR}/cmake/GenRevision.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/EnsureVersion.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/MangosParams.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/SetDefinitions.cmake)

# Precompiled header support (if enabled)
if(PCH)
    include(${CMAKE_SOURCE_DIR}/cmake/PCHSupport.cmake)
endif()

# Add subdirectories for dependencies and source code
add_subdirectory(dep)
add_subdirectory(src)

# Clean up makefiles by removing CMakeLists.txt from the clean files
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES CMakeLists.txt)

# Disable IDE folder structure for final project setup
set_property(GLOBAL PROPERTY USE_FOLDERS OFF)