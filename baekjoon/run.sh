#!/bin/bash

# Usage:
# If you run this script without argument,
# It will compile a latest file ended with .cc or .cpp.
# Then the compile is finished without an error, run the result with the [latest file name].txt
# Also you can choice the file which compile and run by passing filename as first argument
# 
function compileAndRun(){
    local filename=$1
    echo "Compile $filename"
    g++ -std=c++11 -o ${filename%.*}.tmp $filename
    echo "Run $filename with ${filename%.*}.txt"
    echo "---------------------------------------"
    cat ./${filename%.*}.txt | ./${filename%.*}.tmp
    echo "---------------------------------------"
    rm ${filename%.*}.tmp
}

if [ "$1" = "" ]
then
    #Find latest file ending with .cc or .cpp extension
    for filename in $( ls -At ) 
    do
        if [[ $filename == *.cc || $filename == *.cpp ]]
        then
            compileAndRun $filename
            break
        fi
    done
else 
    if [[ -r $1  && ($1 == *.cc || $1 == *.cpp) ]]
    then
        compileAndRun $1
    else
        echo "$1 isn't a right file format or doesn't exist"
    fi
fi

