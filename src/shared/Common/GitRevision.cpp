/* 
 * Project: KeenCore
 * License: GNU General Public License v2.0 or later (GPL-2.0+)
 *
 * This file is part of KeenCore.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 * Originally based on MaNGOS (Massive Network Game Object Server)
 * Copyright (C) 2005-2025 MaNGOS project <https://getmangos.eu>
 */

#include "GitRevision.h"

char const* GitRevision::GetHash()
{
    return REVISION_HASH;
}

char const* GitRevision::GetDate()
{
    return REVISION_DATE;
}

char const* GitRevision::GetBranch()
{
    return REVISION_BRANCH;
}

char const* GitRevision::GetCMakeVersion()
{
    return CMAKE_VERSION;
}

char const* GitRevision::GetHostOSVersion()
{
    return "Compiled on: " CMAKE_HOST_SYSTEM;
}

// Platform Define
#if PLATFORM == PLATFORM_WINDOWS
    #ifdef _WIN64
        #define MANGOS_PLATFORM_STR "Win64"
    #else
        #define MANGOS_PLATFORM_STR "Win32"
    #endif
#elif PLATFORM == PLATFORM_APPLE
    #define MANGOS_PLATFORM_STR "MacOSX"
#elif PLATFORM == PLATFORM_INTEL
    #define MANGOS_PLATFORM_STR "Intel"
#elif PLATFORM == PLATFORM_UNIX
    #define MANGOS_PLATFORM_STR "Linux"
#else
    #define MANGOS_PLATFORM_STR "Unknown System"
#endif

// Database Revision
char const* GitRevision::GetProjectRevision()
{
    return PROJECT_REVISION_NR;
}

char const* GitRevision::GetAuthDBVersion()
{
    return AUTH_DB_VERSION_NR;
}

char const* GitRevision::GetAuthDBStructure()
{
    return AUTH_DB_STRUCTURE_NR;
}

char const* GitRevision::GetAuthDBContent()
{
    return AUTH_DB_CONTENT_NR;
}

char const* GitRevision::GetAuthDBUpdateDescription()
{
    return AUTH_DB_UPDATE_DESCRIPT;
}

char const* GitRevision::GetCharDBVersion()
{
    return CHAR_DB_VERSION_NR;
}

char const* GitRevision::GetCharDBStructure()
{
    return CHAR_DB_STRUCTURE_NR;
}

char const* GitRevision::GetCharDBContent()
{
    return CHAR_DB_CONTENT_NR;
}

char const* GitRevision::GetCharDBUpdateDescription()
{
    return CHAR_DB_UPDATE_DESCRIPT;
}

char const* GitRevision::GetWorldDBVersion()
{
    return WORLD_DB_VERSION_NR;
}

char const* GitRevision::GetWorldDBStructure()
{
    return WORLD_DB_STRUCTURE_NR;
}

char const* GitRevision::GetWorldDBContent()
{
    return WORLD_DB_CONTENT_NR;
}

char const* GitRevision::GetWorldDBUpdateDescription()
{
    return WORLD_DB_UPDATE_DESCRIPT;
}

char const* GitRevision::GetFullRevision()
{
    return "Mangos revision: " VER_PRODUCTVERSION_STR;
}

char const* GitRevision::GetRunningSystem()
{
    return "Running on: " CMAKE_HOST_SYSTEM;
}

char const* GitRevision::GetCompanyNameStr()
{
    return VER_COMPANY_NAME_STR;
}

char const* GitRevision::GetLegalCopyrightStr()
{
    return VER_LEGALCOPYRIGHT_STR;
}

char const* GitRevision::GetFileVersionStr()
{
    return VER_FILEVERSION_STR;
}

char const* GitRevision::GetProductVersionStr()
{
    return VER_PRODUCTVERSION_STR;
}
