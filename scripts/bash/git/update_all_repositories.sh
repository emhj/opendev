#!/bin/bash

scriptName=$0

function usage()
{
    echo "Usage: $scriptName <directory>"
}

if [ -z "$1" ] || [ ! -d "$1" ]; then
    usage
    exit 1
fi

echo $(realpath $0)

scriptLocation=$(dirname $(realpath $0))

updateScript="$scriptLocation/update_local_repository.sh"

if [ ! -e "$updateScript" ]; then
    echo "Could not find $updateScript"
    exit 1
fi

baseDir=$1
directories=($(ls $baseDir))

for (( i=0; i < ${#directories[@]}; i++ )); do

    dirName="${directories[$i]}"
    d="$baseDir/$dirName"

    echo "---------------"
    if [ ! -d $d ]; then
        echo "Skipping $d... not a directory"
        continue
    fi

    # move to the directory
    cd $d

    # check to see if current directory is a git repository
    [ -d .git ] || git rev-parse --git-dir > /dev/null 2>&1
    if [ "$?" -ne "0" ]; then
        echo "$dirName is not a git repository... skipping"
        continue
    fi

    # echo things...
    echo "Updating $dirName repository"

    # update
    $updateScript
done
