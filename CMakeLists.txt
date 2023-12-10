# Rshimgvw --- Independent ReactOS shimgvw

# CMake minimum version
cmake_minimum_required(VERSION 3.5)

# project name and languages
project(Rshimgvw C RC)

##############################################################################
# Architecture

if (MSVC)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        add_definitions(-D_AMD64_ -D_M_AMD64)
    else()
        add_definitions(-D_X86_ -D_M_IX86)
    endif()
endif()

##############################################################################
# shimgvw.exe

add_executable(shimgvw WIN32
    anime.c
    shimgvw.c
    main.c
    shimgvw.rc)

target_compile_definitions(shimgvw PRIVATE
    UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS
    LANGUAGE_BG_BG
    LANGUAGE_CS_CZ
    LANGUAGE_DA_DK
    LANGUAGE_DE_DE
    LANGUAGE_EL_GR
    LANGUAGE_EN_US
    LANGUAGE_ES_ES
    LANGUAGE_ET_EE
    LANGUAGE_EU_ES
    LANGUAGE_FI_FI
    LANGUAGE_FR_FR
    LANGUAGE_HE_IL
    LANGUAGE_HI_IN
    LANGUAGE_HR_HR
    LANGUAGE_HU_HU
    LANGUAGE_HY_AM
    LANGUAGE_ID_ID
    LANGUAGE_IT_IT
    LANGUAGE_JA_JP
    LANGUAGE_KO_KR
    LANGUAGE_LT_LT
    LANGUAGE_MS_MY
    LANGUAGE_NB_NO
    LANGUAGE_NL_NL
    LANGUAGE_NO_NO
    LANGUAGE_PL_PL
    LANGUAGE_PT_BR
    LANGUAGE_PT_PT
    LANGUAGE_RO_RO
    LANGUAGE_RU_RU
    LANGUAGE_SK_SK
    LANGUAGE_SL_SI
    LANGUAGE_SQ_AL
    LANGUAGE_SV_SE
    LANGUAGE_TH_TH
    LANGUAGE_TR_TR
    LANGUAGE_UK_UA
    LANGUAGE_UZ_UZ
    LANGUAGE_ZH_CN
    LANGUAGE_ZH_HK
    LANGUAGE_ZH_TW)

target_compile_definitions(shimgvw PRIVATE -DSTRSAFE_NO_DEPRECATE -D__REACTOS__ -D__RSHIMGVW__)
target_include_directories(shimgvw PUBLIC ./ reactos/)
target_link_libraries(shimgvw PRIVATE gdiplus shlwapi user32 gdi32 comctl32 kernel32)

if (MSVC)
    # No default manifest
    target_link_options(shimgvw PRIVATE /MANIFEST:NO)
endif()

##############################################################################
