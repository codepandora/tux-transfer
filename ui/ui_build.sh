#! /bin/sh

for f in *.ui
do
  uic -o "${f%.ui}.h" "$f"
done 
