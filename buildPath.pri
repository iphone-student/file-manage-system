win32:CONFIG(debug, debug|release){
    EXEC_DIR = $$PWD/build/debug
}
else:win32:CONFIG(release, debug|release){
    EXEC_DIR = $$PWD/build/release
}
else:unix:CONFIG(debug, debug|release){
    EXEC_DIR = $$PWD/buildUnix/debug
}
else:unix:CONFIG(release, debug|release){
    EXEC_DIR = $$PWD/buildUnix/release
}
