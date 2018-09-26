#!/bin/bash
# Watch paths (given as arguments), automatically build when something changes.
# The script does a couple opinionated things to make my life easier:
#
#  * Terminal scrollbuffer is reset before each iteration, simplifying scrolling.
#  * I use a filter script to colorize gcc output (clang errors would be nicer).
#  * Output is copied to a log file (/tmp/build.log).
#    - I open this file in Sublime or vim, which reloads the file on change (each build).
#
# Usage:
#
# devbox:myproject$ mkdir -p build && cd build
# devbox:build$ cmake ..
# devbox:build$ inotify-cmake ../src ../test ../CMakeLists.txt

inotifywait -q -r -e create,modify,move,delete --exclude '\.(swp)' $@ && \
  echo -ne "\033c" && \
  (cmake --build . && echo done.) 2>&1 | tee /tmp/build.log
exec $0 $@
