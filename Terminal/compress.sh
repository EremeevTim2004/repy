#!bin/sh

# Скрипт запаковывает в zip-архив всех .cpp файлов из указанной директории и всех её дочерних директорий без сохранения иерархии

zip -j archive.zip $(find . -type f -name "*.cpp")
