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

#ifndef SOAPTHREAD_H
#define SOAPTHREAD_H

#include "Common.h"
#include <mutex>
#include <future>
#include <string>

void process_message(struct soap* soap_message);
void SoapThread(const std::string& host, uint16 port);

class SOAPCommand
{
public:
    SOAPCommand() : m_success(false) { }
    ~SOAPCommand() { }

    void appendToPrintBuffer(std::string msg)
    {
        m_printBuffer += msg;
    }

    void setCommandSuccess(bool val)
    {
        m_success = val;
        finishedPromise.set_value();
    }

    bool hasCommandSucceeded() const
    {
        return m_success;
    }

    static void print(void* callbackArg, const char* msg)
    {
        ((SOAPCommand*)callbackArg)->appendToPrintBuffer(msg);
    }

    static void commandFinished(void* callbackArg, bool success);

    bool m_success;
    std::string m_printBuffer;
    std::promise<void> finishedPromise;
};

#endif
