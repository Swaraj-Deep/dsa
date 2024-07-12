#!/bin/bash

# Determine the directory of this script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Define paths relative to the script location
INCLUDE_DIR="$SCRIPT_DIR/../include"
SRC_DIR="$SCRIPT_DIR/../src"
BUILD_DIR="$SCRIPT_DIR/../build"

# Compile the project
echo "Compiling the project..."
g++ -std=c++17 -I "$INCLUDE_DIR" "$SRC_DIR"/*.cpp -o "$BUILD_DIR/graph-algorithms"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."

    # Run the executable
    "$BUILD_DIR/graph-algorithms"
else
    echo "Compilation failed. Please check the errors."
fi
