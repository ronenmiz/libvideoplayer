FFMPEG_SRC_PATH="/usr/local/tversity/x64/include"
FFMPEG_LIB_PATH="/usr/local/tversity/x64/lib"

gcc -shared -o libvideoplayer.so cmdutils.c ffplay.c -fPIC -I /usr/include/SDL2 -I /usr/local/include/SDL2 -I $FFMPEG_SRC_PATH -L $FFMPEG_LIB_PATH -lavdevice -lavfilter -lavformat -lavcodec -lavutil -lswscale -lswresample -lSDL2 -lm

gcc main.c -I $FFMPEG_SRC_PATH -I /usr/include/SDL2 -I /usr/local/include/SDL2 -L . -lvideoplayer -L $FFMPEG_LIB_PATH -lavdevice -lavfilter -lavformat -lavcodec -lavutil -lswscale -lswresample -lSDL2 -lm
