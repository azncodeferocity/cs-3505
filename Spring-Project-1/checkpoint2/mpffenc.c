/*
 * MPFF image format encoder
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
 // #include "libavutil/avassert.h"

AVCodec ff_mpff_encoder = {
  .name           = "mpff",
  .long_name      = NULL_IF_CONFIG_SMALL("MPFF image (a CS 3505 project)"),
  .type           = AVMEDIA_TYPE_VIDEO,
  .id             = AV_CODEC_ID_MPFF,
  .init           = mpff_encode_init,
  .close          = mpff_encode_close,
  .encode2        = mpff_encode_frame,
  .pix_fmts       = (const enum AVPixelFormat[]){
      AV_PIX_FMT_BGRA, AV_PIX_FMT_NONE 
  },
};

/* 
 * Initialize encoder and allocate memory
 */
static av_cold int mpff_encode_init(AVCodecContext *avctx)
{
    /* since we are only supporting BGRA we know there are 32 pits per pixel */
    avctx->bits_per_coded_sample = 32; /* Alpha, Red, Green, Blue 8 bits each */

    /* allocate memory for coded image frame */
    avctx->coded_frame = av_frame_alloc();
    if (!avctx->coded_frame)
        return AVERROR(ENOMEM);

    return 0;
}

/* 
 * Encode frame
 */
static int mpff_encode_frame(AVCodecContext *avctx, AVPacket *pkt, const AVFrame *pict, int *got_packet) 
{ 
  const AVFrame * const p = pict;
  int ret = 0; /* return value */






  /* indicates we got the packet and normal return */
  *got_packet = 1;
  return ret; 
}

/* 
 * Close encoder and deallocate memory
 */
static av_cold int mpff_encode_close(AVCodecContext *avctx) 
{
  /* deallocate memory for coded image frame */
  av_frame_free(&avctx->coded_frame);
  return 0;
}



