FFMPEG_PATH="/home/ronenmiz/git/svnTVersity2/CloudBrowser/3rd-party/ffmpeg/ffmpeg-4.3.2"

gcc -shared -o libvideoplayer.so cmdutils.c ffplay.c -fPIC -I /usr/local/tversity/x64/include -I /usr/include/SDL2 -I /usr/local/include/SDL2 -I $FFMPEG_PATH -L /usr/local/tversity/x64/lib -lavdevice -lavfilter -lavformat -lavcodec -lavutil -lswscale -lswresample -lSDL2 -lm

gcc main.c -I /usr/local/tversity/x64/include -I /usr/include/SDL2 -I /usr/local/include/SDL2 -L . -lvideoplayer -L /usr/local/tversity/x64/lib -lavdevice -lavfilter -lavformat -lavcodec -lavutil -lswscale -lswresample -lSDL2 -lm
