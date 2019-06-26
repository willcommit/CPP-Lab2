# Project name
project(dt019g)

# Minimum required cmake version
cmake_minimum_required(VERSION 3.2)

# Compile with c++ 11 support
set(CMAKE_CXX_STANDARD 11)

# Static inclusion of dependencies required for the executable to be independent
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")


# Save name of directories in variables for reuse
#set(LAB_1 "Laboration_1")
#set(LAB_2 "Laboration_2")
set(LAB_3 "Laboration_3")
set(LAB_4 "Laboration_4")
set(LAB_5 "Laboration_5")
set(LAB_6 "Laboration_6")
set(LAB_7 "Laboration_7")
set(LAB_8 "Laboration_8")
set(PROJECT "Project")

# Add source directories for laboration 1
#aux_source_directory(${LAB_1}/src LABORATION_1)

# Add source directories for laboration 2
#aux_source_directory(${LAB_2}/src LABORATION_2)
#aux_source_directory(${LAB_2}/include LABORATION_2)

# Add source directories for laboration 3
aux_source_directory(${LAB_3}/src LABORATION_3)
aux_source_directory(${LAB_3}/include LABORATION_3)

# Add source directories for laboration 4
aux_source_directory(${LAB_4}/src LABORATION_4)

# Add source directories for laboration 5
aux_source_directory(${LAB_5}/src LABORATION_5)

# Add source directories for the project
aux_source_directory(${PROJECT}/src PROJECT_SRC)

# Add executables for all configurations!
#add_executable(${PROJECT_NAME}_${LAB_1} ${LABORATION_1})

#add_executable(${PROJECT_NAME}_${LAB_2} ${LABORATION_2} Laboration_2/src/Lab2.cpp Laboration_2/include/Person.cpp Laboration_2/include/Person.h)
#add_executable(${PROJECT_NAME}_${LAB_2}_AdressTest ${LABORATION_2} Laboration_2/src/AddressTest.cpp Laboration_2/include/Address.cpp Laboration_2/include/Address.h)
#add_executable(${PROJECT_NAME}_${LAB_2}_NameTest ${LABORATION_2} Laboration_2/src/NameTest.cpp)

add_executable(${PROJECT_NAME}_${LAB_3} ${LABORATION_3})

add_executable(${PROJECT_NAME}_${LAB_4} ${LABORATION_4} Laboration_4/include/IntArray.cpp Laboration_4/include/IntArray.h)
add_executable(${PROJECT_NAME}_${LAB_5} ${LABORATION_5})
add_executable(${PROJECT_NAME}_${PROJECT} ${PROJECT_SRC})


# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directories to respective run configuration
#target_include_directories(${PROJECT_NAME}_${LAB_1} PRIVATE "./${LAB_1}/include")

#target_include_directories(${PROJECT_NAME}_${LAB_2} PRIVATE "./${LAB_2}/include")
#target_include_directories(${PROJECT_NAME}_${LAB_2}_AdressTest PRIVATE "./${LAB_2}/include")
#target_include_directories(${PROJECT_NAME}_${LAB_2}_NameTest PRIVATE "./${LAB_2}/include")

target_include_directories(${PROJECT_NAME}_${LAB_3} PRIVATE "./${LAB_3}/include")
target_include_directories(${PROJECT_NAME}_${LAB_4} PRIVATE "./${LAB_4}/include")
target_include_directories(${PROJECT_NAME}_${LAB_5} PRIVATE "./${LAB_5}/include")

target_include_directories(${PROJECT_NAME}_${PROJECT} PRIVATE "./${PROJECT}/include")