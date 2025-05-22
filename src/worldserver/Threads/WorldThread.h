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

#ifndef WORLDTHREAD_H
#define WORLDTHREAD_H

#include <ace/INET_Addr.h>
#include <ace/Task.h>

#include "Common.h"
/**
 * @brief Heartbeat thread for the World
 *
 */
class WorldThread : public ACE_Task_Base
{
    public:
        explicit WorldThread(uint16 port, const char* host);
        int open(void*) override;
        int svc() override;
    private:
        ACE_INET_Addr listen_addr;
};
#endif
/// @}
