# 
# Project: KeenCore
# License: GNU General Public License v2.0 or later (GPL-2.0+)
# This file is part of KeenCore.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Originally based on MaNGOS (Massive Network Game Object Server)
# Copyright (C) 2005-2025 MaNGOS project <https://getmangos.eu>
#

#Account group
file(GLOB SRC_GRP_ACCOUNT Account/*.cpp Account/*.h)
source_group("Account" FILES ${SRC_GRP_ACCOUNT})

# AI group
file(GLOB SRC_GRP_AI AI/*.cpp AI/*.h)
source_group("AI" FILES ${SRC_GRP_AI})

# AuctionHouse group
file(GLOB SRC_GRP_AUCTIONHOUSE AuctionHouse/*.cpp AuctionHouse/*.h)
source_group("AuctionHouse" FILES ${SRC_GRP_AUCTIONHOUSE})

#AH Bot group
file(GLOB SRC_GRP_AHBOT AuctionHouseBot/*.cpp AuctionHouseBot/*.h)
source_group("AhBot" FILES ${SRC_GRP_AHBOT})

#Battlegrounds group
file(GLOB SRC_GRP_BATTLEGROUND BattleGround/*.cpp BattleGround/*.h)
source_group("BattleGround" FILES ${SRC_GRP_BATTLEGROUND})

#Chat group
file(GLOB SRC_GRP_CHAT Chat/*.cpp Chat/*.h)
source_group("Chat" FILES ${SRC_GRP_CHAT})

#Chat Commands group
file(GLOB SRC_GRP_CHAT_COMMANDS ChatCommands/*.cpp ChatCommands/*.h)
source_group("Chat Commands" FILES ${SRC_GRP_CHAT_COMMANDS})

#Entities group
file(GLOB SRC_GRP_ENTITIES Entities/*.cpp Entities/*.h)
source_group("Entities" FILES ${SRC_GRP_ENTITIES})

#GameEvent group
file(GLOB SRC_GRP_GAME_EVENT GameEvent/*.cpp GameEvent/*.h)
source_group("Game Event" FILES ${SRC_GRP_GAME_EVENT})

#GMTicket group
file(GLOB SRC_GRP_GM_TICKET GMTicket/*.cpp GMTicket/*.h)
source_group("GM Ticket" FILES ${SRC_GRP_GM_TICKET})

#Group group
file(GLOB SRC_GRP_GROUP Group/*.cpp Group/*.h)
source_group("Group" FILES ${SRC_GRP_GROUP})

#Guild group
file(GLOB SRC_GRP_GUILD Guild/*.cpp Guild/*.h)
source_group("Guild" FILES ${SRC_GRP_GUILD})

#Handler group
file(GLOB SRC_GRP_HANDLER Handler/*.cpp Handler/*.h)
source_group("Handler" FILES ${SRC_GRP_HANDLER})

#Instance group
file(GLOB SRC_GRP_INSTANCE Instance/*.cpp Instance/*.h)
source_group("Instance" FILES ${SRC_GRP_INSTANCE})

#Items group
file(GLOB SRC_GRP_ITEMS Items/*.cpp Items/*.h)
source_group("Items" FILES ${SRC_GRP_ITEMS})

#Loot group
file(GLOB SRC_GRP_LOOT Loot/*.cpp Loot/*.h)
source_group("Loot" FILES ${SRC_GRP_LOOT})

#Mail group
file(GLOB SRC_GRP_MAIL Mail/*.cpp Mail/*.h)
source_group("Mail" FILES ${SRC_GRP_MAIL})

#Map Threading group
file(GLOB SRC_GRP_MAP_THREAD Maps/*.cpp Maps/*.h)
source_group("Map Threading" FILES ${SRC_GRP_MAP_THREAD})

#Misc group
file(GLOB SRC_GRP_MISC Misc/*.cpp Misc/*.h)
source_group("Misc" FILES ${SRC_GRP_MISC})

#Motion Generator group
file(GLOB SRC_GRP_MOTION_GEN MotionGenerators/*.cpp MotionGenerators/*.h)
source_group("Motion generators" FILES ${SRC_GRP_MOTION_GEN})

#Movement group
file(GLOB SRC_GRP_MOVEMENT Movement/*.cpp Movement/*.h)
source_group("Movement" FILES ${SRC_GRP_MOVEMENT})

#OutdoorPvP group
file(GLOB SRC_GRP_OUTDOOR_PVP OutdoorPvP/*.cpp OutdoorPvP/*.h)
source_group("OutdoorPvP" FILES ${SRC_GRP_OUTDOOR_PVP})

#Pool group
file(GLOB SRC_GRP_POOL Pool/*.cpp Pool/*.h)
source_group("Pool" FILES ${SRC_GRP_POOL})

#Quest group
file(GLOB SRC_GRP_QUEST Quest/*.cpp Quest/*.h)
source_group("Quest" FILES ${SRC_GRP_QUEST})

#References group
file(GLOB SRC_GRP_REFERENCES References/*.cpp References/*.h)
source_group("References" FILES ${SRC_GRP_REFERENCES})

#Reputation group
file(GLOB SRC_GRP_REPUTATION Reputation/*.cpp Reputation/*.h)
source_group("Reputation" FILES ${SRC_GRP_REPUTATION})

#Scripting group
file(GLOB SRC_GRP_SCRIPTING Scripting/*.cpp Scripting/*.h)
source_group("Scripting" FILES ${SRC_GRP_SCRIPTING})

#Server group
file(GLOB SRC_GRP_SERVER Server/*.cpp Server/*.h)
source_group("Server" FILES ${SRC_GRP_SERVER})

#Social group
file(GLOB SRC_GRP_SOCIAL Social/*.cpp Social/*.h)
source_group("Social" FILES ${SRC_GRP_SOCIAL})

#Spell group
file(GLOB SRC_GRP_SPELL Spell/*.cpp Spell/*.h)
source_group("Spell" FILES ${SRC_GRP_SPELL})

#Time group
file(GLOB SRC_GRP_TIME Time/*.cpp Time/*.h)
source_group("Time" FILES ${SRC_GRP_TIME})

#Tools group
file(GLOB SRC_GRP_TOOL Tools/*.cpp Tools/*.h)
source_group("Tool" FILES ${SRC_GRP_TOOL})

#VMap group
file(GLOB SRC_GRP_VMAPS VMap/*.cpp VMap/*.h)
source_group("VMaps" FILES ${SRC_GRP_VMAPS})

#Warden group
file(GLOB SRC_GRP_WARDEN Warden/*.cpp Warden/*.h)
source_group("Warden" FILES ${SRC_GRP_WARDEN})

#Warden Modules group
file(GLOB SRC_GRP_WARDEN_MODULES Warden/Modules/*.cpp Warden/Modules/*.h)
source_group("Warden\\Modules" FILES ${SRC_GRP_WARDEN_MODULES})

#Weather group
file(GLOB SRC_GRP_WEATHER Weather/*.cpp Weather/*.h)
source_group("Weather" FILES ${SRC_GRP_WEATHER})

#Worldgroup
file(GLOB SRC_GRP_WORLD World/*.cpp World/*.h)
source_group("World" FILES ${SRC_GRP_WORLD})

# Build the Eluna library if enabled
if(SCRIPT_LIB_ELUNA)
    file(GLOB SRC_GRP_ELUNA
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/*.cpp
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/*.h
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/hooks/*.cpp
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/hooks/*.h
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/methods/*.cpp
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/methods/*.h
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/methods/Mangos/*.cpp
        ${CMAKE_SOURCE_DIR}/src/modules/Eluna/methods/Mangos/*.h
    )
    source_group("Eluna" FILES ${SRC_GRP_ELUNA})
endif()

if(PLAYERBOTS)

#Base files
file(GLOB Playerbot_Source ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/*.h)
source_group("Player Bot" FILES ${Playerbot_Source})
file(GLOB AHbot_Source ${CMAKE_SOURCE_DIR}/src/modules/Bots/ahbot/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/ahbot/*.h)
source_group("AH Bot" FILES ${AHbot_Source})

set(SRC_GRP_BOTS
    ${Playerbot_Source}
    ${AHbot_Source}
)
#Strategy files
file(GLOB Playerbot_Strategy ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/*.h)
source_group("Player Bot\\Strategies" FILES ${Playerbot_Strategy})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Strategy})

#Action files
file(GLOB Playerbot_Actions ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/actions/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/actions/*.h)
source_group("Player Bot\\Strategies\\Actions" FILES ${Playerbot_Actions})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Actions})

#Generic files
file(GLOB Playerbot_Generic ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/generic/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/generic/*.h)
source_group("Player Bot\\Strategies\\Generic" FILES ${Playerbot_Generic})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Generic})

#Trigger files
file(GLOB Playerbot_Triggers ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/triggers/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/triggers/*.h)
source_group("Player Bot\\Strategies\\Triggers" FILES ${Playerbot_Triggers})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Triggers})


#Value files
file(GLOB Playerbot_Values ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/values/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/values/*.h)
source_group("Player Bot\\Strategies\\Values" FILES ${Playerbot_Values})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Values})

## Class files
#Druid AI
file(GLOB Playerbot_Druid ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/druid/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/druid/*.h)
source_group("Player Bot\\Strategies\\Druid" FILES ${Playerbot_Druid})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Druid})

#Hunter AI
file(GLOB Playerbot_Hunter ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/hunter/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/hunter/*.h)
source_group("Player Bot\\Strategies\\Hunter" FILES ${Playerbot_Hunter})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Hunter})

#Mage AI
file(GLOB Playerbot_Mage ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/mage/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/mage/*.h)
source_group("Player Bot\\Strategies\\Mage" FILES ${Playerbot_Mage})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Mage})

#Paladin AI
file(GLOB Playerbot_Paladin ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/paladin/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/paladin/*.h)
source_group("Player Bot\\Strategies\\Paladin" FILES ${Playerbot_Paladin})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Paladin})

#Priest AI
file(GLOB Playerbot_Priest ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/priest/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/priest/*.h)
source_group("Player Bot\\Strategies\\Priest" FILES ${Playerbot_Priest})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Priest})

#Rogue AI
file(GLOB Playerbot_Rogue ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/rogue/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/rogue/*.h)
source_group("Player Bot\\Strategies\\Rogue" FILES ${Playerbot_Rogue})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Rogue})

#Shaman AI
file(GLOB Playerbot_Shaman ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/shaman/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/shaman/*.h)
source_group("Player Bot\\Strategies\\Shaman" FILES ${Playerbot_Shaman})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Shaman})

#Warlock AI
file(GLOB Playerbot_Warlock ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/warlock/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/warlock/*.h)
source_group("Player Bot\\Strategies\\Warlock" FILES ${Playerbot_Warlock})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Warlock})

#Warrior AI
file(GLOB Playerbot_Warrior ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/warrior/*.cpp ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/strategy/warrior/*.h)
source_group("Player Bot\\Strategies\\Warrior" FILES ${Playerbot_Warrior})
LIST(APPEND SRC_GRP_BOTS ${Playerbot_Warrior})

configure_file(${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot/aiplayerbot.conf.dist.in ${CMAKE_CURRENT_BINARY_DIR}/aiplayerbot.conf.dist)

endif()

configure_file(AuctionHouseBot/ahbot.conf.dist.in ${CMAKE_CURRENT_BINARY_DIR}/AuctionHouseBot/ahbot.conf.dist)

if(BUILD_TOOLS)
add_library(vmap2 STATIC
    vmap/BIH.cpp
    vmap/VMapManager2.cpp
    vmap/MapTree.cpp
    vmap/TileAssembler.cpp
    vmap/WorldModel.cpp
    vmap/ModelInstance.cpp
    vmap/BIH.h
    vmap/VMapManager2.h
    vmap/MapTree.h
    vmap/TileAssembler.h
    vmap/WorldModel.h
    vmap/ModelInstance.h
)

target_include_directories(vmap2
    PUBLIC
        vmap
        WorldHandlers
)

target_compile_definitions(vmap2
    PUBLIC
        MMAP_GENERATOR
        NO_CORE_FUNCS
)
target_link_libraries(vmap2
    PUBLIC
        shared
        g3dlite
        RecastNavigation::Detour
)
endif()

add_library(game STATIC
	${SRC_GRP_ACCOUNT}
	${SRC_GRP_AI}
	${SRC_GRP_AUCTIONHOUSE}
	${SRC_GRP_AHBOT}
	${SRC_GRP_BATTLEGROUND}
	${SRC_GRP_CHAT}
	${SRC_GRP_CHAT_COMMANDS}
	${SRC_GRP_ENTITIES}
	${SRC_GRP_GAME_EVENT}
	${SRC_GRP_GM_TICKET}
	${SRC_GRP_GROUP}
	${SRC_GRP_GUILD}
	${SRC_GRP_HANDLER}
	${SRC_GRP_INSTANCE}
	${SRC_GRP_ITEMS}
	${SRC_GRP_LOOT}
	${SRC_GRP_MAIL}
	${SRC_GRP_MAP_THREAD}
	${SRC_GRP_MISC}
	${SRC_GRP_MOTION_GEN}
	${SRC_GRP_MOVEMENT}
	${SRC_GRP_OUTDOOR_PVP}
	${SRC_GRP_POOL}
	${SRC_GRP_QUEST}
	${SRC_GRP_REFERENCES}
	${SRC_GRP_REPUTATION}
	${SRC_GRP_SCRIPTING}
	${SRC_GRP_SERVER}
	${SRC_GRP_SOCIAL}
	${SRC_GRP_SPELL}
	${SRC_GRP_TIME}
	${SRC_GRP_TOOL}
	${SRC_GRP_VMAPS}
	${SRC_GRP_WARDEN}
	${SRC_GRP_WARDEN_MODULES}
	${SRC_GRP_WEATHER}
	${SRC_GRP_WORLD}
    $<$<BOOL:${SCRIPT_LIB_ELUNA}>:${SRC_GRP_ELUNA}>
    $<$<BOOL:${PLAYERBOTS}>:${SRC_GRP_BOTS}>
)

target_include_directories(game
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
	Account
    AI
	AuctionHouse
	AuctionHouseBot
    BattleGround
    Chat
    ChatCommands
    Entities
    GameEvent
    GMTicket
    Group
	Guild
    Handler
	Instance
	Items
	Loot
	Mail
    Maps
	Misc
    MotionGenerators
    Movement
    OutdoorPvP
	Pool
	Quest
    References
	Reputation
    Scripting
    Server
	Social
	Spell
    Time
    Tools
    VMap
    Warden
    Warden/Modules
	Weather
    World
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:
            ${CMAKE_SOURCE_DIR}/src/modules/Eluna
            ${CMAKE_SOURCE_DIR}/src/modules/Eluna/hooks
            ${CMAKE_SOURCE_DIR}/src/modules/Eluna/methods/Mangos
        >
        $<$<BOOL:${PLAYERBOTS}>:
            ${CMAKE_SOURCE_DIR}/src/modules/Bots
            ${CMAKE_SOURCE_DIR}/src/modules/Bots/playerbot
            ${CMAKE_SOURCE_DIR}/src/modules/Bots/ahbot
        >
)

target_compile_definitions(game
    PUBLIC
        $<$<BOOL:${SOAP}>:ENABLE_SOAP>
        $<$<BOOL:${SCRIPT_LIB_SD3}>:ENABLE_SD3>
        $<$<BOOL:${PLAYERBOTS}>:ENABLE_PLAYERBOTS>
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:ENABLE_ELUNA ELUNA_EXPANSION=0 ELUNA_MANGOS>
)

target_link_libraries(game
    PUBLIC
        shared
        RecastNavigation::Detour
        ZLIB::ZLIB
        g3dlite
		scripts
        $<$<BOOL:${SCRIPT_LIB_ELUNA}>:lualib>
)

# Generate precompiled header
if(PCH)
    add_cxx_pch(game pchdef.h pchdef.cpp)
endif()

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/AuctionHouseBot/ahbot.conf.dist
    DESTINATION ${CONF_INSTALL_DIR}
)

if(SCRIPT_LIB_ELUNA)
install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/src/modules/Eluna/extensions
    DESTINATION ${BIN_DIR}/lua_scripts
)
endif()

if(PLAYERBOTS)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/aiplayerbot.conf.dist
    DESTINATION ${CONF_INSTALL_DIR})
endif()