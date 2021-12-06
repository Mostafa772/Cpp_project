cmake_minimum_required(VERSION 3.20)
project(cockroach_killer)

# Tell CMake to run moc when necessary:
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "/home/mostafa/Qt/6.2.0/gcc_64/lib/cmake")
# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        Test
        )

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt6Widgets_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt6Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt6Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(cockroach_killer main.cpp mainwindow.cpp mainwindow.h
        button.h button.cpp player_one.h player_one.cpp
        game.h game.cpp health.h health.cpp
        player_two.h player_two.cpp score.h score.cpp
        bullet.h bullet.cpp
        tank.png bullet.png background.jpg
        cockroach.png global.cpp global.h)
#tests/tst_first_test.cpp
#        tests/testing_example.cpp tests/testing_example.h
target_link_libraries(cockroach_killer
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Test
        )

