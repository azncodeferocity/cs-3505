/*
 * MPFF image format decoder
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mpff.h"
// #include "libavutil/imgutils.h"

AVCodec ff_mpff_decoder = {
    .name           = "mpff",
    .long_name      = NULL_IF_CONFIG_SMALL("MPFF image (a CS 3505 project)"),
    .type           = AVMEDIA_TYPE_VIDEO,
    .id             = AV_CODEC_ID_MPFF,
    .init           = mpff_decode_init,
    .close          = mpff_decode_end,
    .decode         = mpff_decode_frame,
}

typedef struct MpffState {
  AVCodecContext *avctx;

} MpffState;

/* 
 * Initialize decoder
 */
static av_cold int mpff_decode_init(AVCodecContext *avctx) 
{
  MpffState *m = avctx->priv_data;
  m->avctx = avctx;

  return 0 ;
}


/* 
 * Decode frame
 */
static int mpff_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) 
{

}

/* 
 * Close decoder
 */
static av_cold int mpff_decode_close(AVCodecContext *avctx) 
{

}




