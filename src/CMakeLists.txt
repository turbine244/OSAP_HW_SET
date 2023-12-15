# add every file in MAINTAPP_SOURCES 
file(GLOB MAINAPP_SOURCES "*.cc" "*.h")


# mainApp 
add_executable(mainApp ${MAINAPP_SOURCES})