#include directory
include_directories(
	${PROJECT_SOURCE_DIR}/src
)

#lib directory
link_directories(
	)

set(LIST_SRC
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${PROJECT_SOURCE_DIR}/src/stdafx.cpp
    ${PROJECT_SOURCE_DIR}/src/produce_consumer.cpp	
	)

#create exe
add_executable(produce_consumer ${LIST_SRC})

#link lib
TARGET_LINK_LIBRARIES(produce_consumer 
	pthread	
	)

#output directory
set_target_properties(produce_consumer PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ".."
)

