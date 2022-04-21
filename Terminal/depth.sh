#!bin/sh

# Скрипт определяет "глубину" файла

echo $(find $(fzf) -type f) | tr -cd / | wc -m
