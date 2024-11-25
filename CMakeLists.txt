cmake_minimum_required(VERSION 3.29)
project(Skorowidz_JIMP1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Skorowidz_JIMP1 skorowidz.c
        Skorowidz/Skorowidz/10X/Source/fifo_t.c
)
