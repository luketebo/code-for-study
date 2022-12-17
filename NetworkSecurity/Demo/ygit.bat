@echo off

message = %1
@REM package = %2

git add .
git commit -m message
@REM git push git@github.com:luketebo/package.git

echo "finish"