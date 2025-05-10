cmake_minimum_required(VERSION 3.10)
project(LibraryParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryParser
        main.cpp
        Book.cpp
        Member.cpp
        Reader.cpp
        Parser.cpp
        Shelf.h
        Shelf.cpp
        MemberList.h
        MemberList.cpp
        Library.h
        Library.cpp
)
