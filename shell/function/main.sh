#!/bin/bash  -x

set  -ue

current_srcfile=${BASH_SOURCE:-$0}
script_dir=$(readlink -f "$(dirname "${current_srcfile}")")

test=123

function  main () {
    echo  "current_srcfile = ${current_srcfile}"
    echo  "script_dir = ${script_dir}"

    source  "${script_dir}/subdir/function.sh"

    echo  "current_srcfile = ${current_srcfile}"
    echo  "script_dir = ${script_dir}"

    echo  "test = ${test}"
    echo  "helper_local_val = ${helper_local_val:-'null'}"
    echo  "func_test_val = ${func_test_val}"
}

main  "$@"
