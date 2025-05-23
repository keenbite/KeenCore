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

# Build the shared library
add_subdirectory(shared)
add_subdirectory(genrev)
add_subdirectory(scripts)

# Needs to link against world.lib
if(BUILD_WORLDSERVER)
    # Build the game library
    add_subdirectory(game)
endif()

if(BUILD_WORLDSERVER)
    # Build the world server
    add_subdirectory(worldserver)

    # Build the selected modules
    add_subdirectory(modules)
endif()

# Build the authentication server
if(BUILD_AUTHSERVER)
    add_subdirectory(authserver)
endif()

# If we want the tools for map/vmap/mmap extraction
if(BUILD_TOOLS)
    add_subdirectory(tools)
endif()

# Windows Specific: Install MySQL DLL
if((BUILD_WORLDSERVER OR BUILD_AUTHSERVER) AND WIN32)
    get_filename_component(MYSQL_LIB_DIR "${MySQL_LIBRARIES}" DIRECTORY)
    get_filename_component(MYSQL_LIB_DLL "${MySQL_LIBRARIES}" NAME)
    string(REPLACE ".lib" ".dll" MYSQL_LIB_DLL "${MYSQL_LIB_DLL}")
	
    install(FILES ${MYSQL_LIB_DIR}/${MYSQL_LIB_DLL} DESTINATION ${BIN_DIR})
endif()
