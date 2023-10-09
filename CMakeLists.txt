# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nanopb_demo)

nanopb_generate_cpp(proto_sources proto_headers RELPATH .
    src/protocol.proto
)

target_sources(app PRIVATE src/main.c ${proto_sources})
