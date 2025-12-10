#include <emscripten.h>
#include "libavcodec/avcodec.h"

EMSCRIPTEN_KEEPALIVE
AVCodecContext *init_prores_decoder() {
	const AVCodec *codec = avcodec_find_decoder(AV_CODEC_ID_PRORES);
	if (!codec) return NULL;
	
	AVCodecContext *ctx = avcodec_alloc_context3(codec);
	if (!ctx) return NULL;
	
	if (avcodec_open2(ctx, codec, NULL) < 0) {
		avcodec_free_context(&ctx);
		return NULL;
	}
	
	return ctx;
}