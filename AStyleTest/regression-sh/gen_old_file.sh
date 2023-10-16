#!/bin/bash

# Creates a new test case for a single long option
# if the string begins as flag the second part is stored in OPTS

# Examples:
# ./gen_old_file.sh style_kr
# ./gen_old_file.sh flag_attach-namespaces

# Loop through the command-line arguments
for arg in "$@"; do
    # Split each argument into 'name' and 'value'
    IFS="_" read -r name value <<< "$arg"
	dirName="$arg"
    mkdir -p "$dirName"

    arg="--$name=$value"

	if [ "$name" = "flag" ]; then
	    arg="--$value"
    	echo "$arg" > "$dirName/OPTS"
	fi

	# call the astyle version here which is considered as reference for the future
    astyle_ref "$arg" < tmp.cpp > "$dirName/tmp.cpp.old"
done
