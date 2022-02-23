project(lib_models)

set(lib_models_source board.cpp
		cell.cpp
		database.cpp
		Game.cpp
		ia.cpp
		input.cpp
		Player.cpp
		position.cpp
		serializable.h
		translator.cpp)


add_library(${PROJECT_NAME} ${lib_models_source})
