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

/// \addtogroup authserver
/// @{
/// \file

#ifndef _AUTHSOCKET
#define _AUTHSOCKET

#include "Common.h"
#include "Auth/BigNumber.h"
#include "Auth/Sha1.h"
#include "ByteBuffer.h"
#include "Utilities/Util.h"

#include "SocketBuffer/BufferedSocket.h"

class ACE_INET_Addr;
struct Realm;

/**
 * @brief Handle login commands
 *
 */
class AuthSocket: public BufferedSocket
{
    public:
        const static int s_BYTE_SIZE = 32; /**< TODO */

        /**
         * @brief
         *
         */
        AuthSocket();
        /**
         * @brief
         *
         */
        ~AuthSocket();

        /**
         * @brief
         *
         */
        void OnAccept() override;
        /**
         * @brief
         *
         */
        void OnRead() override;
        /**
         * @brief
         *
         * @param sha
         */
        void SendProof(Sha1Hash sha);
        /**
         * @brief
         *
         * @param pkt
         * @param acctid
         */
        void LoadRealmlist(ByteBuffer& pkt, uint32 acctid);

        static ACE_INET_Addr const& GetAddressForClient(Realm const& realm, ACE_INET_Addr const& clientAddr);

        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleLogonChallenge();
        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleLogonProof();
        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleReconnectChallenge();
        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleReconnectProof();
        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleRealmList();

        /**
         * @brief data transfer handle for patch
         *
         * @return bool
         */
        bool _HandleXferResume();
        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleXferCancel();
        /**
         * @brief
         *
         * @return bool
         */
        bool _HandleXferAccept();

        /**
         * @brief
         *
         * @param rI
         */
        void _SetVSFields(const std::string& rI);

    private:
        enum eStatus
        {
            STATUS_CHALLENGE,
            STATUS_LOGON_PROOF,
            STATUS_RECON_PROOF,
            STATUS_PATCH,
            STATUS_AUTHED,
            STATUS_CLOSED
        };

        BigNumber N, s, g, v; /**< TODO */
        BigNumber b, B; /**< TODO */
        BigNumber K; /**< TODO */
        BigNumber _reconnectProof; /**< TODO */

        eStatus _status; /**< TODO */

        std::string _login; /**< TODO */
        std::string _safelogin; /**< TODO */

        std::string _localizationName; /**< Since GetLocaleByName() is _NOT_ bijective, we have to store the locale as a string. Otherwise we can't differ between enUS and enGB, which is important for the patch system */
        std::string _os;
        uint16 _build; /**< TODO */
        AccountTypes _accountSecurityLevel; /**< TODO */

        ACE_HANDLE patch_; /**< TODO */

        /**
         * @brief
         *
         */
        void InitPatch();
};
#endif
/// @}
