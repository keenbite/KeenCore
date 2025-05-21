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

# Main Files
set(SRC_GRP_MAIN
  AFThread.cpp
  AFThread.h
  CliThread.cpp
  CliThread.h
  RAThread.cpp
  RAThread.h
  WorldThread.cpp
  WorldThread.h
  mangosd.cpp
)
source_group("Main" FILES ${SRC_GRP_MAIN})

set(SRC_GRP_SOAP
  SOAP/SoapThread.cpp
  SOAP/SoapThread.h
)
source_group("SOAP" FILES ${SRC_GRP_SOAP})

# Generate configuration file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mangosd.conf.dist.in ${CMAKE_CURRENT_BINARY_DIR}/mangosd.conf.dist)

if( WIN32 )
  set(mangosd_SRCS
    ${mangosd_SRCS}
    mangosd.rc)
endif()

# Create executable
add_executable(mangosd
    ${SRC_GRP_MAIN}
    $<$<BOOL:${SOAP}>:${SRC_GRP_SOAP}>
	${mangosd_SRCS}
)

target_include_directories(mangosd
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${OPENSSL_INCLUDE_DIR}
)

target_compile_definitions(mangosd
    PUBLIC
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:ENABLE_ELUNA ELUNA_EXPANSION=0 ELUNA_MANGOS>
)

target_link_libraries(mangosd
    PUBLIC
        game
        $<$<BOOL:${SOAP}>:gsoap>
        Threads::Threads
        ${OPENSSL_LIBRARIES}
		OpenSSL::Crypto
)
		
# Installation
install(TARGETS mangosd DESTINATION ${BIN_DIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/mangosd.conf.dist DESTINATION ${CONF_INSTALL_DIR})

if(WIN32 AND MSVC)
    install(
        FILES $<TARGET_PDB_FILE:mangosd>
        DESTINATION ${BIN_DIR}
        OPTIONAL
        )
endif()
