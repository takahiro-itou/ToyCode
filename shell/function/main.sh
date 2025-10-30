#!/bin/bash  -x

set  -ue

current_srcfile=${BASH_SOURCE:-$0}
script_dir=$(readlink -f "$(dirname "${current_srcfile}")")

test=123

function  main () {
    echo  "main::main"  1>&2

    echo  "\$0 = $0"
    echo  "current_srcfile = ${current_srcfile}"
    echo  "script_dir = ${script_dir}"

    source  "${script_dir}/subdir/function.sh"

    echo  "\$0 = $0"
    echo  "current_srcfile = ${current_srcfile}"
    echo  "script_dir = ${script_dir}"

    echo  "test = ${test}"
    echo  "helper_local_val = ${helper_local_val:-'null'}"
    echo  "func_test_val = ${func_test_val}"
}

main  "$@"
main  "$@"
