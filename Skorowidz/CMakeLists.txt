cmake_minimum_required(VERSION 3.29)
project(Skorowidz_JIMP1 C)

# Wersja języka C
set(CMAKE_C_STANDARD 11)

# Dodanie katalogu z plikami nagłówkowymi
include_directories(Skorowidz/10X/Headers)

# Lista plików źródłowych
set(SOURCES
        Skorowidz/10X/Sources/fifo_t.c
        Skorowidz/10X/Sources/load_file.c
        Skorowidz/10X/Sources/search.c
        Skorowidz/10X/Sources/kw_t.c
        Skorowidz/10X/Sources/sort.c
        Skorowidz/10X/Sources/compare.c
        skorowidz.c  # Główna funkcja programu
)

# Tworzenie pliku wykonywalnego
add_executable(skorowidz ${SOURCES})
