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

#ifndef ANTIFREEZE_THREAD
#define ANTIFREEZE_THREAD

#include "ace/Task.h"
#include "Common.h"

class AntiFreezeThread : public ACE_Task_Base
{
    public:
        explicit AntiFreezeThread(uint32 delay);
        int open(void*) override;
        int svc() override;

    private:
        uint32 m_loops;
        uint32 m_lastchange;
        uint32 w_loops;
        uint32 w_lastchange;
        uint32 delaytime_;
};

#endif