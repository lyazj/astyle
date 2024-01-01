#!/bin/sh

# run all test cases in the current directory
# it assumes a source file produced by a previous astyle version to compare with the output of the current
#

for dir in */
do
    dir=${dir%*/}      # remove the trailing "/"

	# make string an array
	cmd_arg=(${dir//_/ })

	# default arg=val based on directory name
	arg="--${cmd_arg[0]}=${cmd_arg[1]}"

	# custom arguments
	if [ -f "$dir/OPTS" ]; then
  		arg=$(<"$dir/OPTS")
	fi

	# call the latest astyle here
	../../AStyle/build_local/astyle --squeeze-lines=1 "$arg"  < tmp.cpp > "$dir/tmp.cpp.new"
	diff $dir/tmp.cpp.old $dir/tmp.cpp.new
	if [ $? -eq 0 ]; then
		rm "$dir/tmp.cpp.new"
	else
		echo "${dir} -> FAILED"
		exit 1
	fi
done
