# CMakeList.txt: SoftRendererApp 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

project (MathUtils 
    VERSION 1.0.0 
    LANGUAGES C CXX
    DESCRIPTION "This is a math library")

if (MSVC)
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

# 添加预定义宏
add_compile_definitions(MATH_UTILS_DLL)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

# 头文件包含目录
include_directories(
	${INCLUDE_DIR}
)

file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_library(MathUtils SHARED ${SOURCES})

# 确定架构
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH_DIR "x64")
else()
    set(ARCH_DIR "x86")
endif()

# 设置输出目录
set_target_properties(MathUtils PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/libs/${ARCH_DIR}/${CMAKE_BUILD_TYPE}"    # .lib 存放位置
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/bin/${ARCH_DIR}/${CMAKE_BUILD_TYPE}"    # .dll 存放位置
)

# 使用message命令打印变量名及其值
macro(print_variable var)
    message(STATUS "${var} = ${${var}}")
endmacro()

# 调用宏以打印变量名及其值
print_variable(CMAKE_BUILD_TYPE)