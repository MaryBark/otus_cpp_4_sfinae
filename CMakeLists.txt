cmake_minimum_required(VERSION 3.2)

project(IP_print VERSION 0.0.${PATCH_VERSION})

#project(print_ip VERSION 0.0.$ENV{PATCH_VERSION})

#project(IP_print LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(untitled4 main.cpp)
configure_file(version.h.in version.h)

add_executable(IP_print main.cpp print_ip_file.cpp)

set_target_properties(IP_print PROPERTIES
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        CMAKE_CXX_STANDARD 17
        CMAKE_CXX_STANDARD_REQUIRED ON
)


install(TARGETS IP_print RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

include(CPack)
