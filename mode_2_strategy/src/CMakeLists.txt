#include directory
include_directories(
	${PROJECT_SOURCE_DIR}/src
)

#lib directory
link_directories(
	)

set(LIST_SRC
	main.cpp
	stdafx.cpp
	by_bus.cpp
	context.cpp
	take_a_walk.cpp
	)

#create exe
add_executable(strategy_mode ${LIST_SRC})

#link lib
TARGET_LINK_LIBRARIES(strategy_mode 
	pthread	
	)

#output directory
set_target_properties(strategy_mode PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ".."
)

