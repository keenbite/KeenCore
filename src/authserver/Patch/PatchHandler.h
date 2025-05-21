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

/** \file
  \ingroup authserver
  */

#ifndef _PATCHHANDLER
#define _PATCHHANDLER

#include <ace/Basic_Types.h>
#include <ace/Synch_Traits.h>
#include <ace/Svc_Handler.h>
#include <ace/SOCK_Stream.h>
#include <ace/Message_Block.h>
#include <ace/Auto_Ptr.h>
#include <map>

#include <openssl/bn.h>
#include <openssl/md5.h>

/**
 * @brief Caches MD5 hash of client patches present on the server
 *
 */
class PatchCache
{
    public:
        /**
         * @brief
         *
         */
        ~PatchCache();
        /**
         * @brief
         *
         */
        PatchCache();

        /**
         * @brief
         *
         * @return PatchCache
         */
        static PatchCache* instance();

        /**
         * @brief
         *
         */
        struct PATCH_INFO
        {
            ACE_UINT8 md5[MD5_DIGEST_LENGTH]; /**< TODO */
        };

        /**
         * @brief
         *
         */
        typedef std::map<std::string, PATCH_INFO*> Patches;

        /**
         * @brief
         *
         * @return Patches::const_iterator
         */
        Patches::const_iterator begin() const
        {
            return patches_.begin();
        }

        /**
         * @brief
         *
         * @return Patches::const_iterator
         */
        Patches::const_iterator end() const
        {
            return patches_.end();
        }

        /**
         * @brief
         *
         * @param
         */
        void LoadPatchMD5(const char*);
        /**
         * @brief
         *
         * @param pat
         * @param mymd5[]
         * @return bool
         */
        bool GetHash(const char* pat, ACE_UINT8 mymd5[MD5_DIGEST_LENGTH]);

    private:
        /**
         * @brief
         *
         */
        void LoadPatchesInfo();
        Patches patches_; /**< TODO */
};

/**
 * @brief
 *
 */
class PatchHandler: public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
    protected:
        /**
         * @brief
         *
         */
        typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> Base;

    public:
        /**
         * @brief
         *
         * @param socket
         * @param patch
         */
        PatchHandler(ACE_HANDLE socket, ACE_HANDLE patch);
        /**
         * @brief
         *
         */
        virtual ~PatchHandler();

        int open(void* = 0) override;

    protected:
        int svc(void) override;

    private:
        ACE_HANDLE patch_fd_; /**< TODO */
};

#endif /* _BK_PATCHHANDLER_H__ */

