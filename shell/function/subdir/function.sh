#!/bin/bash

function  testfunc () {

local   current_srcfile=${BASH_SOURCE:-$0}
local   script_dir=$(readlink -f "$(dirname "${current_srcfile}")")

}

testfunc
