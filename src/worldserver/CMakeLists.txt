# 
# Project: KeenCore
# License: GNU General Public License v2.0 or later (GPL-2.0+)
#
# This file is part of KeenCore.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
#
# Originally based on MaNGOS (Massive Network Game Object Server)
# Copyright (C) 2005-2025 MaNGOS project <https://getmangos.eu>
#

# === Options ===
option(SOAP "Enable SOAP support" ON)
option(SCRIPT_LIB_ELUNA "Enable Eluna scripting support" OFF)

# === Sources ===
set(THREAD_SRC
    threads/AFThread.cpp
    threads/AFThread.h
    threads/CliThread.cpp
    threads/CliThread.h
    threads/RAThread.cpp
    threads/RAThread.h
    threads/WorldThread.cpp
    threads/WorldThread.h
)

set(SOAP_SRC
    SOAP/SoapThread.cpp
    SOAP/SoapThread.h
)

set(MAIN_SRC
    Main.cpp
)

# Optional Windows resource
if(WIN32)
    list(APPEND MAIN_SRC worldserver.rc)
endif()

# === Executable ===
add_executable(worldserver
    ${MAIN_SRC}
    ${THREAD_SRC}
    $<$<BOOL:${SOAP}>:${SOAP_SRC}>
)

# === Include Directories ===
target_include_directories(worldserver
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${OPENSSL_INCLUDE_DIR}
)

# === Compiler Definitions ===
target_compile_definitions(worldserver
    PUBLIC
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:ENABLE_ELUNA>
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:ELUNA_EXPANSION=0>
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:ELUNA_MANGOS>
)

# === Link Libraries ===
target_link_libraries(worldserver
    PUBLIC
        game
        $<$<BOOL:${SOAP}>:gsoap>
        Threads::Threads
        ${OPENSSL_LIBRARIES}
        OpenSSL::Crypto
)

# === Source Groups (for IDEs like Visual Studio) ===
source_group("Main" FILES ${MAIN_SRC})
source_group("Threads" FILES ${THREAD_SRC})
source_group("SOAP" FILES ${SOAP_SRC})

# === Configuration File ===
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/worldserver.conf.dist.in
    ${CMAKE_CURRENT_BINARY_DIR}/worldserver.conf.dist
)

# === Installation ===
install(TARGETS worldserver DESTINATION ${BIN_DIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/worldserver.conf.dist DESTINATION ${CONF_INSTALL_DIR})

if(WIN32 AND MSVC)
    install(
        FILES $<TARGET_PDB_FILE:worldserver>
        DESTINATION ${BIN_DIR}
        OPTIONAL
    )
endif()
