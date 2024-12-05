cmake_minimum_required(VERSION 3.29)
project(Skorowidz_JIMP1 C)

# Wersja języka C
set(CMAKE_C_STANDARD 11)

# Dodanie katalogu z plikami nagłówkowymi
include_directories(Skorowidz/10X/Headers)

# Lista plików źródłowych
set(SOURCES
        Sources/fifo_t.c
        Sources/load_file.c
        Sources/search.c
        Sources/kw_t.c
        Sources/sort.c
        Sources/compare.c
        skorowidz.c
        Sources/compare.c  # Główna funkcja programu
)

# Tworzenie pliku wykonywalnego
add_executable(skorowidz ${SOURCES}
        Sources/compare.c)
