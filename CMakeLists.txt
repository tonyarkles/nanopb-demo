# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nanopb_demo)

list(APPEND CMAKE_MODULE_PATH ${ZEPHYR_BASE}/modules/nanopb)
include(nanopb)

zephyr_nanopb_sources(app src/demo.proto)

# nanopb_generate_cpp(proto_sources proto_headers RELPATH .
#     src/protocol.proto
# )

target_sources(app PRIVATE src/main.c)
