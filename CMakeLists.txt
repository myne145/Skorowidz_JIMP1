cmake_minimum_required(VERSION 3.29)
project(Skorowidz_JIMP1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Skorowidz_JIMP1 skorowidz.c
        Skorowidz/Skorowidz/10X/Sources/fifo_t.c
        Skorowidz/Skorowidz/10X/Sources/load_file.c
        Skorowidz/Skorowidz/10X/Headers/load_file.h
        Skorowidz/Skorowidz/10X/Headers/search.h
        Skorowidz/Skorowidz/10X/Sources/search.c
        Skorowidz/Skorowidz/10X/Headers/kw_t.h
        Skorowidz/Skorowidz/10X/Sources/kw_t.c
        Skorowidz/Skorowidz/10X/Sources/sort.c
        Skorowidz/Skorowidz/10X/Headers/compare.h
        Skorowidz/Skorowidz/10X/Sources/compare.c
        Skorowidz/Skorowidz/10X/Headers/sort.h
)
