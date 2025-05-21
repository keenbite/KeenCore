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

#ifndef GITREVISION_H
#define GITREVISION_H

#include "Define.h"

#include "revision_data.h"

namespace GitRevision
{
    // github data
    char const* GetHash();
    char const* GetDate();
    char const* GetBranch();

    // system data
    char const* GetCMakeVersion();
    char const* GetHostOSVersion();
    char const* GetRunningSystem();

    // database data
    char const* GetProjectRevision();
    char const* GetAuthDBVersion();
    char const* GetAuthDBStructure();
    char const* GetAuthDBContent();
    char const* GetAuthDBUpdateDescription();

    char const* GetCharDBVersion();
    char const* GetCharDBStructure();
    char const* GetCharDBContent();
    char const* GetCharDBUpdateDescription();

    char const* GetWorldDBVersion();
    char const* GetWorldDBStructure();
    char const* GetWorldDBContent();
    char const* GetWorldDBUpdateDescription();

    // application data
    char const* GetFullRevision();
    char const* GetCompanyNameStr();
    char const* GetLegalCopyrightStr();
    char const* GetFileVersionStr();
    char const* GetProductVersionStr();
}

#endif
