```bash
emconfigure ./configure \
    --disable-x86asm \
    --disable-inline-asm \
    --disable-doc \
    --disable-stripping \
    --disable-all \
    --enable-avcodec \
    --enable-decoder=prores \
    --enable-cross-compile \
    --cc=emcc \
    --extra-cflags="-DNDEBUG -O3 -msimd128"
```

```bash
export FFMPEG_PATH=/path/to/ffmpeg

emcc src/bridge.c \
    $FFMPEG_PATH/libavcodec/libavcodec.a \
    $FFMPEG_PATH/libavutil/libavutil.a \
    -I$FFMPEG_PATH \
    -s MODULARIZE=1 \
    -s EXPORT_ES6=1 \
    -s SINGLE_FILE=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s ENVIRONMENT=web,worker \
    -s EXPORTED_RUNTIME_METHODS=cwrap,HEAPU8 \
    -s EXPORTED_FUNCTIONS=_malloc,_free \
    -msimd128 \
    -O3 \
    -o build/prores.js
```