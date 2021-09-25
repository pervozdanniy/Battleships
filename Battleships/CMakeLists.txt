# CMakeList.txt: проект CMake для Battleships; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Battleships "Battleships.cpp" "Battleships.h"  "entities/Ship.h" "entities/Ship.cpp" "entities/Field.h" "entities/Board.h" "entities/Board.cpp" "entities/Coord.h" "Player.h" "Player.cpp" "players/ConsolePlayer.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
