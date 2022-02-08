#include <stdio.h>
#include <SDL.h>

#include "videoplayer.h" 


int main(int argc, char **argv)
{
    vp_handle_t is1 = NULL, is2 = NULL;

    if (argc != 2)
    {
        printf("Usage: %s <video file/url>", argv[0]);
        exit(-1);
    }

    vp_init();

    is1 = vp_open(argv[1], NULL, NULL, 0, 1, 0, 0);
    if (!is1) {
        fprintf(stderr, "Failed to initialize video!\n");
        vp_terminate();
    }

    is2 = vp_open("http://localhost:8080/osb/session/ui?session_id=appf&fmt=h264&ts_discon=0", NULL, NULL, 0, 1, 1, 1);
    if (!is2) {
        fprintf(stderr, "Failed to initialize VideoState!\n");
        vp_terminate();
    }

    // vp_event_loop(is1);
    vp_event_loop(NULL, NULL);

    vp_close(is1);
    vp_close(is2);
    return 0;
}
