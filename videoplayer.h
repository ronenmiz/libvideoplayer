#ifndef __videoplayer__

#define __videoplayer__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    VP_STREAM_NULL_EVENT,
    VP_STREAM_OPENED_EVENT,
    VP_STREAM_PAUSE_EVENT,
    VP_STREAM_PLAY_EVENT,
    VP_STREAM_SEEKING_EVENT,
    VP_STREAM_SEEKED_EVENT
} vp_stream_event_type_t;


typedef void *vp_handle_t;

typedef int vp_event_handler_t(void *event, void *user_data);


int vp_init();

void vp_terminate();

void vp_toggle_full_screen();

vp_handle_t vp_open(const char *url, int is_paused, int is_auto_resize, int is_overlay, int is_low_latency, char *img_mime_type, char *alfa_mime_type);

void vp_close(vp_handle_t handle);

void vp_set_rect(vp_handle_t handle, int x, int y, int w, int h);

void vp_set_size(vp_handle_t handle, int width, int height);

void vp_get_size(vp_handle_t handle, int *width, int *height);

int vp_get_video_size(vp_handle_t handle, int *width, int *height);

void vp_event_loop(vp_event_handler_t *event_handler, void *user_data);

int vp_is_stream_event(void *event, vp_stream_event_type_t *event_type, vp_handle_t *ret_handle);

// Force redraw last frame (useful when resizing window)
void vp_force_refresh(vp_handle_t handle);

void vp_toggle_pause(vp_handle_t handle);

int vp_is_paused(vp_handle_t handle);

int vp_is_seeking(vp_handle_t handle);

int vp_is_seekable(vp_handle_t handle);

// Negative or zero means duration is not known
double vp_get_duration(vp_handle_t handle);

// should check validity with !isnan()
double vp_get_current_time(vp_handle_t handle);

void vp_seek(vp_handle_t handle, double pos);


void vp_seek_rel(vp_handle_t handle, double incr);

void vp_seek_chapter(vp_handle_t handle, int incr);

void vp_toggle_mute(vp_handle_t handle);

void vp_update_volume(vp_handle_t handle, int up);

void vp_step_to_next_frame(vp_handle_t handle);

void vp_cycle_channel_audio(vp_handle_t handle);

void vp_cycle_channel_video(vp_handle_t handle);

void vp_cycle_channel_subtitle(vp_handle_t handle);

#ifdef __cplusplus
}
#endif

#endif // ndef __videoplayer__