#!/bin/bash

# 检查是否提供了源文件
if [ -z "$1" ]; then
  echo "Usage: $0 <source_file.cpp>"
  exit 1
fi

SOURCE_FILE=$1
EXECUTABLE=${SOURCE_FILE%.cpp}.out
INPUT_FILE=${SOURCE_FILE%.cpp}.in

# 检查输入文件是否存在
if [ ! -f "$INPUT_FILE" ]; then
  echo "Input file $INPUT_FILE not found."
  exit 1
fi

# 使用 clang++ 编译源文件
clang++ -o $EXECUTABLE $SOURCE_FILE
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# 运行编译后的程序并使用输入文件
echo "Running with input file: $INPUT_FILE"
./$EXECUTABLE <$INPUT_FILE
