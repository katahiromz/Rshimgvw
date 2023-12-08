#!/usr/bin/env bash

cp -fr ../reactos/dll/win32/shimgvw/lang/ .
cp -fr ../reactos/dll/win32/shimgvw/res/ .
cp -fr ../reactos/dll/win32/shimgvw/*.c .
cp -fr ../reactos/dll/win32/shimgvw/*.h .
cp -fr ../reactos/dll/win32/shimgvw/*.rc .
cp -fr ../reactos/output-MinGW-i386/sdk/include/reactos/version.h reactos/
cp -fr ../reactos/output-MinGW-i386/sdk/include/reactos/buildno.h reactos/
