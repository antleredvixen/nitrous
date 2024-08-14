# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\nitrous_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\nitrous_autogen.dir\\ParseCache.txt"
  "nitrous_autogen"
  )
endif()
