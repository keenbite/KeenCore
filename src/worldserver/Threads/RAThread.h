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

#ifndef RATHREAD_H
#define RATHREAD_H

#include <ace/SOCK_Acceptor.h>
#include <ace/Acceptor.h>
#include <ace/Task.h>
#include <ace/INET_Addr.h>
#include "Common.h"

class RASocket;
class ACE_Reactor;

typedef ACE_Acceptor < RASocket, ACE_SOCK_ACCEPTOR > RAAcceptor;

class RAThread : public ACE_Task_Base
{
    private:
        ACE_Reactor    *m_Reactor;
        RAAcceptor     *m_Acceptor;
        ACE_INET_Addr  listen_addr;

    public:
        explicit RAThread(uint16 port, const char* host);
        virtual ~RAThread();

        int open(void* unused) override;
        int svc() override;
};

#endif

