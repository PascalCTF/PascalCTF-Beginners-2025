#include <drm_fourcc.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#define BITMAP_H 16
#define BITMAP_W 12
#define FLAG "pascalCTF{L1nUx_gr4ph1cs}"
#define FLAG_LEN (sizeof FLAG)

const static uint16_t bitmap[][BITMAP_H] = {
    // Each character is 12x16, stored as 16 rows of 16-bit values.
    /* 'p' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x7F8, 0x7FC, 0x60E, 0x606, 0x606, 0x70E, 0x7FC, 0x6F8, 0x600, 0x600, 0x600},
    /* 'a' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x1FC, 0x3FE, 0x006, 0x1FE, 0x3FE, 0x606, 0x606, 0x7FE, 0x3FE, 0x000, 0x000},
    /* 's' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x3F0, 0x7F8, 0x600, 0x7F0, 0x3F8, 0x018, 0x018, 0x7F8, 0x3F0, 0x000, 0x000},
    /* 'c' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x1F8, 0x3FC, 0x706, 0x600, 0x600, 0x600, 0x706, 0x3FC, 0x1F8, 0x000, 0x000},
    /* 'a' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x1FC, 0x3FE, 0x006, 0x1FE, 0x3FE, 0x606, 0x606, 0x7FE, 0x3FE, 0x000, 0x000},
    /* 'l' */ {0x0E0, 0x0E0, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x1F8, 0x1F8, 0x000, 0x000},
    /* 'C' */ {0x0F8, 0x1FC, 0x38E, 0x306, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x306, 0x38E, 0x1FC, 0x0F8, 0x000, 0x000},
    /* 'T' */ {0x3FC, 0x3FC, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x060, 0x000, 0x000},
    /* 'F' */ {0x7FE, 0x7FE, 0x600, 0x600, 0x600, 0x600, 0x7F8, 0x7F8, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x000, 0x000},
    /* '{' */ {0x03C, 0x07C, 0x0E0, 0x0C0, 0x0C0, 0x0C0, 0x1C0, 0x380, 0x1C0, 0x0C0, 0x0C0, 0x0C0, 0x0E0, 0x07C, 0x03C, 0x000},
    /* 'L' */ {0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x600, 0x7FE, 0x7FE, 0x000, 0x000},
    /* '1' */ {0x030, 0x070, 0x1F0, 0x1F0, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x1FE, 0x1FE, 0x000, 0x000},
    /* 'n' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x3F8, 0x3FC, 0x30E, 0x306, 0x306, 0x306, 0x306, 0x306, 0x306, 0x000, 0x000},
    /* 'U' */ {0x606, 0x606, 0x606, 0x606, 0x606, 0x606, 0x606, 0x606, 0x606, 0x606, 0x606, 0x30C, 0x3FC, 0x1F8, 0x000, 0x000},
    /* 'x' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x60C, 0x71C, 0x3B8, 0x1F0, 0x0E0, 0x1F0, 0x3B8, 0x71C, 0x60C, 0x000, 0x000},
    /* '_' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x7FF, 0x7FF, 0x000, 0x000},
    /* 'g' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x1FE, 0x3FE, 0x706, 0x606, 0x70E, 0x3FE, 0x1F6, 0x006, 0x00E, 0x3FC, 0x3F8},
    /* 'r' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x37C, 0x3FE, 0x386, 0x300, 0x300, 0x300, 0x300, 0x300, 0x300, 0x000, 0x000},
    /* '4' */ {0x01C, 0x03C, 0x07C, 0x0EC, 0x1CC, 0x38C, 0x70C, 0x60C, 0x7FF, 0x7FF, 0x00C, 0x00C, 0x00C, 0x00C, 0x000, 0x000},
    /* 'p' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x7F8, 0x7FC, 0x60E, 0x606, 0x606, 0x70E, 0x7FC, 0x6F8, 0x600, 0x600, 0x600},
    /* 'h' */ {0x600, 0x600, 0x600, 0x600, 0x600, 0x6F0, 0x7F8, 0x71C, 0x60C, 0x60C, 0x60C, 0x60C, 0x60C, 0x60C, 0x000, 0x000},
    /* '1' */ {0x030, 0x070, 0x1F0, 0x1F0, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x1FE, 0x1FE, 0x000, 0x000},
    /* 'c' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x1F8, 0x3FC, 0x706, 0x600, 0x600, 0x600, 0x706, 0x3FC, 0x1F8, 0x000, 0x000},
    /* 's' */ {0x000, 0x000, 0x000, 0x000, 0x000, 0x3F0, 0x7F8, 0x600, 0x7F0, 0x3F8, 0x018, 0x018, 0x7F8, 0x3F0, 0x000, 0x000},
    /* '}' */ {0x3C0, 0x3E0, 0x070, 0x030, 0x030, 0x030, 0x038, 0x01C, 0x038, 0x030, 0x030, 0x030, 0x070, 0x3E0, 0x3C0, 0x000},
};

typedef struct
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t x;

} Pixel;

struct dumb_framebuffer {
    uint32_t id; // DRM object ID
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    uint32_t handle; // driver-specific handle
    uint64_t size;   // size of mapping

    Pixel *data; // mmapped data we can write to
};

drmModeCrtc *find_crtc(int drm_fd, drmModeConnector *conn, drmModeRes *res) {
    drmModeCrtc *crtc = NULL;
    for (int i = 0; i < conn->count_encoders; i++) {
        drmModeEncoder *enc = drmModeGetEncoder(drm_fd, conn->encoders[i]);
        if (!enc) {
            perror("drmModeGetEncoder");
            continue;
        }
        for (int j = 0; j < res->count_crtcs; j++) {
            uint32_t bit = 1 << j;
            if (enc->possible_crtcs & bit) {
                crtc = drmModeGetCrtc(drm_fd, res->crtcs[j]);
                if (crtc)
                    return crtc;
                else
                    perror("drmModeGetCrtc");
            }
        }

        drmModeFreeEncoder(enc);
    }
    return NULL;
}

// Function to draw a string at a specific position
void draw_flag(Pixel *buffer, int width, int height) {
    int startX = (width - FLAG_LEN * BITMAP_W) / 2;
    int startY = (height - BITMAP_H) / 2;
    for (int char_idx = 0; char_idx < FLAG_LEN - 1; char_idx++) {
        for (int bm_row = 0; bm_row < BITMAP_H; bm_row++) {
            for (int bm_col = 0; bm_col < BITMAP_W; bm_col++) {

                if (bitmap[char_idx][bm_row] & (1 << (BITMAP_W - bm_col))) {
                    int px = startX + bm_col;
                    int py = startY + bm_row;
                    if (px >= 0 && px < width && py >= 0 && py < height) {
                        buffer[py * width + px].red = 0;
                        buffer[py * width + px].green = 0;
                        buffer[py * width + px].blue = 0;
                        buffer[py * width + px].x = 0;
                    }
                }
            }
        }
        // Move to the next character position
        startX += BITMAP_W;
    }
}

int main(void) {
    /* We just take the first GPU that works. */
    const char *path[] = {
        "/dev/dri/card0",
        "/dev/dri/card1",
        "/dev/dri/card2",
        "/dev/dri/card3"};

    int drm_fd = -1;
    drmModeRes *res = NULL;
    int ret = 0;
    for (int i = 0; (!res || drm_fd < 0) && i < 4; i++) {
        drm_fd = open(path[i], O_RDWR | O_NONBLOCK);
        if (drm_fd < 0) {
            perror(path[i]);
            close(drm_fd);
            continue;
        }

        /* Get resources associated with that device */
        res = drmModeGetResources(drm_fd);

        if (!res) {
            perror("drmModeGetResources");
            close(drm_fd);
        }
    }

    if (!res || drm_fd < 0) exit(0);

    /* Find a connected connector */
    drmModeConnector *conn = NULL;
    for (int i = 0; i < res->count_connectors; i++) {
        conn = drmModeGetConnector(drm_fd, res->connectors[i]);
        if (!conn) {
            perror("drmModeGetConnector");
            exit(0);
        }

        if (conn->connection == DRM_MODE_CONNECTED)
            break;

        drmModeFreeConnector(conn);
    }

    /* Select mode to use */
    // First one is the best
    drmModeModeInfo used_mode = conn->modes[0];

    // Find a crtc compatible with the encoders
    drmModeCrtc *crtc = find_crtc(drm_fd, conn, res);
    if (crtc == NULL) {
        printf("Could not find a CRTC\n");
        exit(0);
    }

    // Allocate framebuffer
    struct dumb_framebuffer fb = {
        .height = used_mode.vdisplay,
        .width = used_mode.hdisplay,
    };

    ret = drmModeCreateDumbBuffer(drm_fd, fb.width, fb.height, 32, 0,
                                  &(fb.handle), &(fb.stride), &(fb.size));
    if (ret < 0) {
        perror("DRM_IOCTL_MODE_CREATE_DUMB");
        exit(0);
    }

    uint32_t handles[4] = {fb.handle, 0, 0, 0};
    uint32_t pitches[4] = {fb.stride, 0, 0, 0};
    uint32_t offsets[4] = {0, 0, 0, 0};
    ret = drmModeAddFB2(drm_fd, fb.width, fb.height, DRM_FORMAT_XRGB8888, handles,
                        pitches, offsets, &(fb.id), 0);

    if (ret < 0) {
        perror("drmModeAddFB2");
        exit(0);
    }

    uint64_t offset = 0;
    ret = drmModeMapDumbBuffer(drm_fd, fb.handle, &offset);
    if (ret < 0) {
        perror("drmModeMapDump");
        exit(0);
    }

    fb.data = mmap(0, fb.size, PROT_WRITE | PROT_READ, MAP_SHARED, drm_fd, offset);
    if (!fb.data) {
        perror("mmap");
        exit(0);
    }
    
    // Set crtc mode and bind framebuffer
    drmModeCrtc* backup = drmModeGetCrtc(drm_fd, crtc->crtc_id);
    ret = drmModeSetCrtc(drm_fd, crtc->crtc_id, fb.id, 0, 0,
                         &(conn->connector_id), 1, &used_mode);
    if (ret < 0) {
        perror("drmModeSetCrtc");
        exit(0);
    }

    // Write framebuffer
    memset(fb.data, 0xff, fb.size);
    draw_flag((Pixel *)fb.data, fb.width, fb.height);
    #ifdef DEV
    sleep(10);
    #endif

    munmap(fb.data, fb.size);
    drmModeRmFB(drm_fd, fb.id);
    drmModeDestroyDumbBuffer(drm_fd, fb.handle);
    drmModeFreeCrtc(crtc);

    if (backup) {
        drmModeSetCrtc(drm_fd, backup->crtc_id, backup->buffer_id,
                       backup->x, backup->y, &(conn->connector_id), 1, &crtc->mode);
        drmModeFreeCrtc(backup);
    }
    drmModeFreeConnector(conn);
    drmModeFreeResources(res);
    close(drm_fd);
}
