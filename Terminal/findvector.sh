#!bin/sh

# Скрипт находи все файлы содержащие директиву "#include <vector>"

grep -r "#include <vector>" $(find . -type f -name "*.cpp") | cut -d':' -f 1
