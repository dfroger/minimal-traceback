#!/bin/bash

# Check the file is sourced.
if [ "${BASH_SOURCE[0]}" == "${0}" ]
then 
    echo "===================================================="
    echo "WARNING: Usage: source set_up_env_bash.sh"
    echo "===================================================="
    echo
fi

function pyrealpath ()
{
    python -c "import os; print os.path.realpath('$1')"
}

SCRIPT_DIR=$(pyrealpath $(dirname ${BASH_SOURCE[0]}))
ROOT_DIR=$(pyrealpath $SCRIPT_DIR/..)
INSTALL_DIR=$ROOT_DIR/install

PYTHON_MAJOR=$(python -c 'import sys; print sys.version_info.major')
PYTHON_MINOR=$(python -c 'import sys; print sys.version_info.minor')

INC_DIR=$INSTALL_DIR/include
LIB_DIR=$INSTALL_DIR/lib

export LIBRARY_PATH=$LIB_DIR:$LIBRARY_PATH
export LD_LIBRARY_PATH=$LIB_DIR:$LD_LIBRARY_PATH
export C_INCLUDE_PATH=$INC_DIR:$C_INCLUDE_PATH

echo "LIBRARY_PATH    prepended with   : $LIB_DIR"
echo "LD_LIBRARY_PATH prepended with   : $LIB_DIR"
echo "C_INCLUDE_PATH  prepended with   : $INC_DIR"
