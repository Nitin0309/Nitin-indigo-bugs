if(NOT MSVC)
	set(VISIBILITY_HIDDEN YES)
endif()
if (NOT CMAKE_BUILD_TYPE)
	if(NOT BUILD_DEBUG)
		 MESSAGE(STATUS "Set CMAKE_BUILD_TYPE to Release")
		 set(CMAKE_BUILD_TYPE Release)
	else()
		 MESSAGE(STATUS "Set CMAKE_BUILD_TYPE to Debug")
		 set(CMAKE_BUILD_TYPE Debug)
	endif()
endif()
MESSAGE(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
if(UNIX)
	if (SUBSYSTEM_NAME MATCHES "x86")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")	
	elseif(SUBSYSTEM_NAME MATCHES "x64")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
	endif()
endif()
if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "i386;x86_64")
    set(CMAKE_OSX_SYSROOT /Developer/SDKs/MacOSX${SUBSYSTEM_NAME}.sdk) 
    set(CMAKE_OSX_DEPLOYMENT_TARGET ${SUBSYSTEM_NAME})
    message(STATUS "SDK: ${CMAKE_OSX_SYSROOT}")
    message(STATUS "Deployment target: ${CMAKE_OSX_DEPLOYMENT_TARGET}")
endif()
if(VISIBILITY_HIDDEN)
    SET(COMPILE_FLAGS "${COMPILE_FLAGS} -fvisibility=hidden")
endif()   
if(UNIX OR APPLE)
    SET(COMPILE_FLAGS "${COMPILE_FLAGS} -fPIC")
endif()
#Set RPATH 
if(UNIX OR APPLE)
        SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
        SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
        if(APPLE)
                SET(CMAKE_INSTALL_RPATH "\@loader_path")
        else()
                SET(CMAKE_INSTALL_RPATH "\$ORIGIN")
        endif()
        SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()
