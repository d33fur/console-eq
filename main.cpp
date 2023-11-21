#include <iostream>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <ncurses.h>

#define BUFSIZE 1024

int main() {
    pa_sample_spec ss;
    ss.format = PA_SAMPLE_S16LE;
    ss.channels = 1;
    ss.rate = 44100;
    pa_simple *s = NULL;
    int error;

    if (!(s = pa_simple_new(NULL, "AudioSpectrogram", PA_STREAM_RECORD, NULL, "record", &ss, NULL, NULL, &error))) {
        fprintf(stderr, "pa_simple_new() failed: %s\n", pa_strerror(error));
        return -1;
    }

    initscr();
    timeout(0);

    int16_t buf[BUFSIZE]; 
    while (1) {
        if (pa_simple_read(s, buf, sizeof(buf), &error) < 0) {
            fprintf(stderr, "pa_simple_read() failed: %s\n", pa_strerror(error));
            break;
        }

        clear();

        for (int i = 0; i < BUFSIZE; i++) {
            mvprintw(0, i, "%c", buf[i] > 0 ? '+' : '-');
        }

        refresh();

        if (getch() == 'q') {
            break;
        }
    }


    if (s) {
        pa_simple_free(s);
    }

    endwin();

    return 0;
}
