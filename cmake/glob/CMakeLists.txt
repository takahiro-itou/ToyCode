
##----------------------------------------------------------------
##
##    Package Configurations.
##    パッケージ設定。
##

##
##    要求するツールのバージョンを指定する。
##

cmake_minimum_required(VERSION  3.0.2)

##
##    パッケージの情報を指定する。
##

set(project_name        Sample)
set(serial              "0.0.0")

project(${project_name}     VERSION  1.0.0)


##----------------------------------------------------------------

file(GLOB  file_glob_1  "*-export.cmake")
message("file_glob_1 = ${file_glob_1}")

file(GLOB  file_glob_2  "subdir/*/*-export.cmake")
message("file_glob_2 = ${file_glob_2}")

ForEach (target_file  ${file_glob_2})
    message("Found target_file = ${target_file}")
EndForEach ()
