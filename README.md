# ESP32 TFT Display Image Viewer

A simple ESP32 project that displays a full-screen image on a TFT display in portrait mode.

## Features

- **Full-screen image display** in portrait orientation
- **Perfect fit** - 320x480 image on 320x480 display
- **No borders or black areas** - image fills entire screen
- **High-quality bitmap format** - no JPEG decoder issues
- **Optimized for ESP32** - efficient memory usage

## Hardware Requirements

- ESP32 development board
- TFT display (320x480 pixels recommended)
- SPI connections for TFT display

## Required Libraries

- `TFT_eSPI` - TFT display library
- `TJpg_Decoder` - JPEG decoder (included but not used in final version)

## Files

- `sketch_sep06c.ino` - Main Arduino sketch
- `picture_bitmap.h` - Image data in 16-bit bitmap format
- `picture.jpg` - Original source image

## How It Works

1. The ESP32 initializes the TFT display in portrait mode (rotation 0)
2. The image is converted to a 16-bit RGB565 bitmap format
3. The bitmap is stored as a C array in `picture_bitmap.h`
4. The image is displayed using `tft.pushImage()` for maximum performance

## Image Conversion

The image was converted from JPEG to bitmap format using a Python script:
- Original: 480x636 pixels JPEG
- Converted: 320x480 pixels RGB565 bitmap
- File size: ~1.2MB (153,600 pixels × 2 bytes)

## Display Configuration

- **Display rotation**: 0 (portrait mode)
- **Image dimensions**: 320x480 pixels
- **Color format**: RGB565 (16-bit)
- **Display method**: Direct bitmap rendering

## Usage

1. Upload the sketch to your ESP32
2. Connect your TFT display via SPI
3. The image will display automatically on startup
4. Colored test rectangles appear first, then the main image

## Performance

- **Startup time**: ~2 seconds
- **Image rendering**: Instant (pre-loaded bitmap)
- **Memory usage**: Optimized for ESP32 flash storage
- **Display quality**: High resolution, no compression artifacts

## Troubleshooting

- If you see a white screen: Check TFT display connections
- If image doesn't fit: Verify display is 320x480 pixels
- If colors are wrong: Check `setSwapBytes(true)` setting

## License

This project is open source and available under the MIT License.
