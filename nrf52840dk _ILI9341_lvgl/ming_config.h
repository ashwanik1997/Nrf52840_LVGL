
#ifndef __MG_MING_CONFIG_H_
#define __MG_MING_CONFIG_H_

    #include "../../ming_config.default.h"

    #undef MG_WIDTH
    #define MG_WIDTH 128

    #undef MG_HEIGHT
    #define MG_HEIGHT 160

    #undef MG_BUFFER_COUNT
    #define MG_BUFFER_COUNT 2 

    #undef MG_BUFFER_SIZE
    #define MG_BUFFER_SIZE (255)

    #undef MG_FRAMEBUFFER_ENDIANNESS
    #define MG_FRAMEBUFFER_ENDIANNESS MG_FRAMEBUFFER_ENDIANNESS_BE

    #undef MG_COLOR_FORMAT
    #define MG_COLOR_FORMAT MG_COLOR_FORMAT_RGB565

    #define MG_DEBUG 1

#endif
