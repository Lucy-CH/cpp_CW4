#!/bin/sh
make -C /Users/lecheng/desktop/CPPCoursework2020-v101/build -f /Users/lecheng/desktop/CPPCoursework2020-v101/build/CMakeScripts/SDL2_App_preBuildCommands.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
