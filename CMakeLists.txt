cmake_minimum_required(VERSION 3.10)
project(PFL C)

# Версия проекта
set(PROJECT_VERSION "1.0.0")

# Стандарт C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Флаги компилятора
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

# Если не указан тип сборки, используем Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Поиск GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Директории включаемых файлов
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GTK3_INCLUDE_DIRS})

# Исходные файлы
set(SOURCES
    src/main.c
    src/menu_events.c
    src/Drawing_events.c
    src/Color_buttons.c
    src/globals.c
)

# Заголовочные файлы
set(HEADERS
    include/PFL.h
)

# Создание исполняемого файла
add_executable(PFL ${SOURCES} ${HEADERS})

# Линковка с GTK3
target_link_libraries(PFL ${GTK3_LIBRARIES})
target_compile_options(PFL PRIVATE ${GTK3_CFLAGS_OTHER})

# Установка флагов для отладки
if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
    message(STATUS "Сборка в режиме Debug")
else()
    message(STATUS "Сборка в режиме Release")
endif()

# Информация о сборке
message(STATUS "Проект: ${PROJECT_NAME} ${PROJECT_VERSION}")
message(STATUS "Компилятор: ${CMAKE_C_COMPILER}")
message(STATUS "Тип сборки: ${CMAKE_BUILD_TYPE}")
message(STATUS "GTK+ версия: ${GTK3_VERSION}")
