#!/bin/bash

# Determine the directory of this script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

BUILD_DIR="$SCRIPT_DIR/../build"

"$BUILD_DIR/graph-algorithms"
