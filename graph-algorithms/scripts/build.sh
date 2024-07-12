#!/bin/bash

# Get the current directory of the script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Compile all source files in src/ and output binaries to build/
g++ -std=c++11 -I $SCRIPT_DIR/../include $SCRIPT_DIR/../src/*.cpp -o $SCRIPT_DIR/../build/graph-algorithms
