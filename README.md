# SPI TFT with ESP32

A beginner-friendly ESP32 project to display images on a TFT LCD touchscreen display using SPI communication. This project shows how to display your pictures or any image in full-screen portrait mode.

## 🖼️ Features

- **Full-screen image display** in portrait mode (320x480)
- **High-quality bitmap format** (no JPEG decoder issues)
- **Touchscreen support** (wiring included)
- **Optimized for ESP32** with efficient memory usage
- **Beginner-friendly** with detailed documentation

## 📋 Hardware Requirements

- **ESP32 development board** (ESP32-WROOM-32 or similar)
- **TFT LCD Touchscreen** (3.5" or 2.8" with 320x480 resolution)
- **Connecting wires** (Dupont wires or breadboard)
- **Power supply** (5V or 3.3V)

## 🔌 Pin Connection Diagram

| TFT LCD Touchscreen | ESP32 Pin | Description |
|---------------------|-----------|-------------|
| **T_IRQ** | **GPIO 36** | Touch Interrupt |
| **T_OUT** | **GPIO 39** | Touch Data Out |
| **T_DIN** | **GPIO 32** | Touch Data In |
| **T_CS** | **GPIO 33** | Touch Chip Select |
| **T_CLK** | **GPIO 25** | Touch Clock |
| **SDO (MISO)** | **GPIO 12** | SPI Master In Slave Out |
| **LED** | **GPIO 21** | Backlight Control |
| **SCK** | **GPIO 14** | SPI Clock |
| **SDI (MOSI)** | **GPIO 13** | SPI Master Out Slave In |
| **D/C** | **GPIO 2** | Data/Command |
| **RESET** | **EN/RESET** | Reset Pin |
| **CS** | **GPIO 15** | Chip Select |
| **GND** | **GND** | Ground |
| **VCC** | **5V or 3.3V** | Power Supply |

### 🔋 Power Supply Options

- **5V**: For displays that require 5V (most common)
- **3.3V**: For 3.3V compatible displays
- **Backlight**: Can be controlled via GPIO 21 for power saving

## 💻 Software Requirements

- **Arduino IDE** (version 1.8.19 or newer)
- **ESP32 board package** (version 2.0.0 or newer)
- **Required Libraries**:
  - TFT_eSPI (version 2.4.70 or newer)
  - TJpg_Decoder (optional, for JPEG support)

## 🚀 Installation Guide

### Step 1: Install Arduino IDE
1. Download Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Install and launch Arduino IDE

### Step 2: Install ESP32 Board Package
1. Open Arduino IDE
2. Go to **File → Preferences**
3. Add this URL to **Additional Board Manager URLs**:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to **Tools → Board → Boards Manager**
5. Search for "ESP32" and install **ESP32 by Espressif Systems**

### Step 3: Install Required Libraries
1. Go to **Tools → Manage Libraries**
2. Search and install:
   - **TFT_eSPI** by Bodmer
   - **TJpg_Decoder** by Bodmer (optional)

### Step 4: Configure TFT_eSPI Library
1. Navigate to your Arduino libraries folder
2. Open `TFT_eSPI/User_Setup.h`
3. Uncomment the line for your display type:
   ```cpp
   #define ILI9341_DRIVER
   ```
4. Set the correct pins (usually already configured for ESP32)

### Step 5: Select Board and Port
1. Go to **Tools → Board → ESP32 Arduino → ESP32 Dev Module**
2. Go to **Tools → Port** and select your ESP32's COM port

## 📁 Project Files

- **`sketch_sep06c.ino`** - Main Arduino code
- **`MyPicture_bitmap.h`** - Image data in bitmap format (1.23MB)
- **`MyPicture.png`** - Original source image
- **`image_to_bitmap_converter.py`** - Ready-to-use image converter script ⭐
- **`README.md`** - This documentation
- **`PIN_DIAGRAM.md`** - Visual connection guide
- **`BEGINNER_GUIDE.md`** - Step-by-step tutorial
- **`LICENSE`** - MIT License

## 🎯 Usage Instructions

### Step 1: Hardware Setup
1. **Power off** your ESP32
2. **Connect all wires** according to the pin diagram above
3. **Double-check** all connections
4. **Power on** your ESP32

### Step 2: Upload Code
1. Open `sketch_sep06c.ino` in Arduino IDE
2. Click **Upload** button (or Ctrl+U)
3. Wait for upload to complete

### Step 3: View Results
The display will show:
1. **Colored test rectangles** (Red, Green, Blue) for 2 seconds
2. **Your picture** in full-screen portrait mode
3. **Status text overlay** showing "MY PICTURE!"

## 🖼️ Displaying Your Own Images

### Method 1: Ready-to-Use Converter (Recommended) ⭐
**Use the included Python converter script:**

1. **Install Python PIL library**:
   ```bash
   pip install Pillow
   ```

2. **Run the converter**:
   ```bash
   python3 image_to_bitmap_converter.py your_image.jpg my_image
   ```

3. **Examples**:
   ```bash
   # Convert with default 320x480 size
   python3 image_to_bitmap_converter.py photo.jpg my_photo
   
   # Convert with custom size
   python3 image_to_bitmap_converter.py image.png my_image 240 320
   ```

4. **Update Arduino code**:
   ```cpp
   #include "my_image_bitmap.h"
   tft.pushImage(0, 0, my_image_bitmap_width, my_image_bitmap_height, my_image_bitmap);
   ```

### Method 2: Manual Python Script
1. **Prepare your image**: Resize to 320x480 pixels
2. **Create conversion script**:
   ```python
   from PIL import Image
   
   def image_to_bitmap_c_array(image_file, output_file, array_name, width=320, height=480):
       img = Image.open(image_file)
       img = img.resize((width, height), Image.LANCZOS)
       if img.mode != 'RGB':
           img = img.convert('RGB')
       
       with open(output_file, 'w') as f:
           f.write(f"const uint16_t {array_name}[] = {{\n")
           for y in range(height):
               f.write("  ")
               for x in range(width):
                   r, g, b = img.getpixel((x, y))
                   rgb565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
                   f.write(f"0x{rgb565:04X}, ")
               f.write("\n")
           f.write("};\n")
           f.write(f"const int {array_name}_width = {width};\n")
           f.write(f"const int {array_name}_height = {height};\n")
   
   image_to_bitmap_c_array("your_image.jpg", "your_image_bitmap.h", "your_image_bitmap")
   ```

3. **Update Arduino code**:
   ```cpp
   #include "your_image_bitmap.h"
   // Change MyPicture_bitmap to your_image_bitmap in the code
   ```

### Method 3: Online Converter
1. Use online image to C array converters
2. Set output format to RGB565
3. Set dimensions to 320x480

## 🔧 Troubleshooting

### Common Issues:

**1. Display shows nothing (black screen)**
- Check power connections (VCC and GND)
- Verify all pin connections
- Check if backlight is working (LED pin)

**2. Display shows garbled colors**
- Check SPI connections (SCK, MOSI, MISO)
- Verify D/C and CS pins
- Check TFT_eSPI library configuration

**3. Upload fails**
- Check USB cable (use data cable, not charging cable)
- Press and hold BOOT button while uploading
- Check COM port selection

**4. Image not displaying**
- Verify image file is included correctly
- Check image dimensions (must be 320x480)
- Ensure bitmap format is correct

### Serial Monitor Output:
```
Starting ESP32 TFT Display Test...
TFT initialized in portrait mode: 320x480 pixels
TFT initialized and screen cleared
Testing TFT display...
TFT test completed
Testing your picture as bitmap...
Image size: 320x480 pixels
Portrait full screen image: 320x480 pixels
Display size in portrait mode: 320x480 pixels
Your picture drawing completed!
```

## 📊 Technical Specifications

- **Display Resolution**: 320x480 pixels
- **Color Depth**: 16-bit RGB565
- **Image Format**: Bitmap (no compression)
- **Memory Usage**: ~1.23MB for 320x480 image
- **Refresh Rate**: Real-time display
- **Touch Support**: Available (wiring included)

## 🎨 Display Modes

### Portrait Mode (Current)
- **Rotation**: 0 degrees
- **Dimensions**: 320x480 pixels
- **Best for**: Portrait photos, documents

### Landscape Mode (Alternative)
- **Rotation**: 1 degree
- **Dimensions**: 480x320 pixels
- **Best for**: Landscape photos, videos

## 🔄 Switching Between Images

To switch between different images:

1. **Convert your new image** using the Python script
2. **Update the include** in `sketch_sep06c.ino`:
   ```cpp
   #include "new_image_bitmap.h"
   ```
3. **Update variable names** in the code:
   ```cpp
   tft.pushImage(0, 0, new_image_bitmap_width, new_image_bitmap_height, new_image_bitmap);
   ```

## 📱 Touchscreen Features

The touchscreen is wired and ready to use. To add touch functionality:

1. **Include touch library**:
   ```cpp
   #include "XPT2046_Touchscreen.h"
   ```

2. **Initialize touchscreen**:
   ```cpp
   XPT2046_Touchscreen ts(CS_PIN);
   ```

3. **Read touch coordinates**:
   ```cpp
   if (ts.touched()) {
     TS_Point p = ts.getPoint();
     // Process touch coordinates
   }
   ```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 📄 License

MIT License - see LICENSE file for details

## 🙏 Acknowledgments

- **Bodmer** for TFT_eSPI library
- **Espressif** for ESP32 platform
- **Arduino** community for support

---

**Happy coding! 🚀** If you have any questions, please open an issue on GitHub.

## 📞 Support

For beginners who need help:
1. Check the troubleshooting section above
2. Verify all connections match the pin diagram
3. Ensure you have the correct libraries installed
4. Open an issue on GitHub with your specific problem

**Remember**: Always double-check your wiring before powering on! 🔌