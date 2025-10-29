#!/bin/bash

function  testfunc () {

local   current_srcfile=${BASH_SOURCE:-$0}
local   script_dir=$(readlink -f "$(dirname "${current_srcfile}")")

echo  "\$0 = $0"
echo  "current_srcfile = ${current_srcfile}"
echo  "script_dir = ${script_dir}"

local   test

test=999

source  "${script_dir}/helper.rc"

}

testfunc
