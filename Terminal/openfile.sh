#!bin/sh

# Скрипт предоставляет возможность выбора любого файла из домашней директории и всех поддиректорий и его открывает в текстовом редакторе nano.

nano $(find ~ -type f | fzf)
