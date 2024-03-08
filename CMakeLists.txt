cmake_minimum_required(VERSION 3.22.3)
project(PJC)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG        a33701196adfad74917046096bf5a2aa0ab0bb50
)

FetchContent_MakeAvailable(fmt)

#Notatunie
#======================================================
add_executable(PJC_Notatunie Notatunie/main.cpp)
target_link_libraries(PJC_Notatunie fmt)
#======================================================
#ćwiczenia 1
#======================================================
add_executable(PJC_cw1_z1 cw1/zliczanie_znakow.cpp)
add_executable(PJC_cw1_z2 cw1/zliczanie_liczb.cpp)
add_executable(PJC_cw1_z3 cw1/usuwanie_duplikatow.cpp)
#======================================================
#ćwiczenia 2
#======================================================
add_executable(PJC_cw2_kartkowkaNasza cw2/kartkowkanNasza.cpp)
add_executable(PJC_cw2_z1 cw2/z1.cpp)
add_executable(PJC_cw2_z2 cw2/z2.cpp)
#======================================================
#ćwiczenia 3
#======================================================
add_executable(PJC_cw3_z1 cw3/z1.cpp)
target_link_libraries(PJC_cw3_z1 fmt)
#======================================================
#ćwiczenia 4
#======================================================
add_executable(PJC_cw4_z1 cw4/z1.cpp)
target_link_libraries(PJC_cw4_z1 fmt)
add_executable(PJC_cw4_z2 cw4/z2.cpp)
target_link_libraries(PJC_cw4_z2 fmt)
add_executable(PJC_cw4_z3 cw4/z3.cpp)
target_link_libraries(PJC_cw4_z3 fmt)
#======================================================
#ćwiczenia 5
#======================================================
add_executable(PJC_cw5_kartkowkaPrzyklad cw5/kartkowkaPrzykladowa/kartkowkaPrzyklad.cpp)
target_link_libraries(PJC_cw5_kartkowkaPrzyklad fmt)
add_executable(PJC_cw5_z1 cw5/z1/z1.cpp)
target_link_libraries(PJC_cw5_z1 fmt)
#======================================================
#ćwiczenia 6
#======================================================
add_executable(PJC_cw6_z1 cw6/z1/z1.cpp)
target_link_libraries(PJC_cw6_z1 fmt)
add_executable(PJC_cw6_z2 cw6/z2/z2.cpp)
target_link_libraries(PJC_cw6_z2 fmt)
add_executable(PJC_cw6_kartkowka cw6/kartkowka/kartkowka.cpp)
target_link_libraries(PJC_cw6_kartkowka fmt)
#======================================================
#ćwiczenia 7
#======================================================
add_executable(PJC_cw7_kartkowka cw7/kartkowka/kartkowkaPrzykladowa.cpp)
target_link_libraries(PJC_cw7_kartkowka fmt)
#======================================================
#ćwiczenia 8
#======================================================
add_executable(PJC_cw8_kartkowka cw8/kartkowka/przykladowa.cpp)
target_link_libraries(PJC_cw8_kartkowka fmt)
add_executable(PJC_cw8_z1 cw8/z1/z1.cpp)
target_link_libraries(PJC_cw8_z1 fmt)
#======================================================
#ćwiczenia 9
#======================================================
add_executable(PJC_cw9_kartkowka cw9/kartkowkaPrzyklad/przykladowa.cpp)
target_link_libraries(PJC_cw9_kartkowka fmt)
add_executable(PJC_cw9_kartkowka2 cw9/kartkowkaPrzyklad/przykladowa2.cpp)
target_link_libraries(PJC_cw9_kartkowka2 fmt)
#add_executable(PJC_cw9_kartkowkaNasza cw9/kartkowkaNasza/kartkowka.cpp)
#target_link_libraries(PJC_cw9_kartkowkaNasza fmt)
#======================================================