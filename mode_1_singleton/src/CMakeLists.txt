#include directory
include_directories(
	${PROJECT_SOURCE_DIR}/src
)

#lib directory
link_directories(
	)

set(LIST_SRC
	#${PROJECT_SOURCE_DIR}/src/main.cpp
	#${PROJECT_SOURCE_DIR}/src/stdafx.cpp
	main.cpp
	stdafx.cpp
	)

#aux_source_directory(. LIST_SRC)

#create exe
#add_executable(singleton_mode main.cpp stdafx.cpp)
add_executable(singleton_mode ${LIST_SRC})

#link lib
TARGET_LINK_LIBRARIES(singleton_mode 
	pthread	
	)

#output directory
set_target_properties(singleton_mode PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ".."
)

