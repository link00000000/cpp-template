# cpp-template
A template for cpp applications

## Setup
1. git clone git@github.com:link00000000/cpp-template.git <project_name>
2. cd <project_name>
3. sh cleanup.sh

*Note: https://github.com/link00000000/cpp-template.git can be used as a replacement when cloning*

## Usage
1. cd build
2. cmake ..
3. cmake --build .
4. ./my_project

## Watch and auto compile (linux only)
1. cd build
2. cmake ..
3. ../inotify-cmake.sh

## Debugging
Run commands under either *Usage* or *Watch and auto compile*
In a separate terminal
1. gdm build/my_project
