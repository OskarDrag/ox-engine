@ECHO OFF

REM this file pushes the project to this git repo
REM https://github.com/OskarDrag/ox-engine

git add .

git commit -m "version 0.1.1"

git push origin main