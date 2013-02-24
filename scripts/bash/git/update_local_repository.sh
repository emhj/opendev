#!/bin/bash

# check to see if current directory is a git repository
[ -d .git ] || git rev-parse --git-dir > /dev/null 2>&1

if [ "$?" -ne "0" ]; then
    echo "$PWD does not contain a git repository"
    exit 1
fi

# update local repository
git fetch origin

if [ "$?" -ne "0" ]; then
    echo "Error fetching from origin"
    exit 1
fi

# grab local branches and versions
localBranches=($(git branch -av | sed 's@^\*\?\s\+@@g' | sed 's@\s\+@ @g' | grep -v 'remotes' | cut -d' ' -f1))
localVersions=($(git branch -av | sed 's@^\*\?\s\+@@g' | sed 's@\s\+@ @g' | grep -v 'remotes' | cut -d' ' -f2))

# grab current branch
curBranch=$(git branch -av | grep '*' | sed 's@^\*\?\s\+@@g' | sed 's@\s\+@ @g' | grep -v 'remotes' | cut -d' ' -f1)

echo "Current branch: $curBranch"

# preemptively stash changes
git stash
if [ "$?" -ne "0" ]; then
    echo "Error stashing changes"
fi

for (( i=0; i<${#localBranches[@]}; i++ )); do
    # check to see if there's a remote version for this branch
    locBranch=${localBranches[$i]}
    locVersion=${localVersions[$i]}
    remoteBranchName="remotes/origin/$locBranch"
    remoteBranch=$(git branch -av | sed 's@^\*\?\s\+@@g' | sed 's@\s\+@ @g' | grep "$remoteBranchName" | cut -d' ' -f1)
    remoteVersion=$(git branch -av | sed 's@^\*\?\s\+@@g' | sed 's@\s\+@ @g' | grep "$remoteBranchName" | cut -d' ' -f2) 

    if [ -z "$remoteBranch" ]; then
        echo "No remote branch for $locBranch... skipping"
        continue
    fi

    if [ -z "$remoteVersion" ]; then
        echo "No remote version for $remoteBranch... skipping"
        continue
    fi

    if [ "$locVersion" != "$remoteVersion" ]; then
        echo "Updating $locBranch to $remoteVersion"
        git checkout $locBranch
        if [ "$?" -ne "0" ]; then
            echo "Error checking out $locBranch"
            exit 1
        fi

        echo "Merging updates"
        git merge $remoteBranchName
        if [ "$?" -ne "0" ]; then
            echo "Error merging changes"
        fi
    fi
done

# checkout current branch
git checkout $curBranch
if [ "$?" -ne "0" ]; then
    echo "Error checking out $curBranch"
    exit 1
fi

# pop changes
git stash pop
