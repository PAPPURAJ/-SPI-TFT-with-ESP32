# 🖼️ SPI TFT with ESP32

<div align="center">

![ESP32 TFT Display](https://img.shields.io/badge/ESP32-TFT%20Display-blue?style=for-the-badge&logo=arduino)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Python](https://img.shields.io/badge/Python-3.x-yellow?style=for-the-badge&logo=python)

**A beginner-friendly ESP32 project to display images on TFT LCD displays using SPI communication**

[![Output Preview](Output_Picture.jpg)](Output_Picture.jpg)

*Click image to view full size - Actual ESP32 TFT display output*

</div>

---

## ✨ Features

- 🖼️ **Full-screen image display** in portrait mode (320x480)
- 🚀 **High-quality bitmap format** (no JPEG decoder issues)
- 📱 **Touchscreen support** (optional - wiring included)
- ⚡ **Optimized for ESP32** with efficient memory usage
- 🎯 **Beginner-friendly** with detailed documentation
- 🛠️ **Ready-to-use image converter** included

---

## 🛒 What You Need

### Hardware
- **ESP32 Development Board** (~$8-12)
- **TFT LCD Touchscreen 3.5"** (~$15-25) 
- **Dupont Wires** (~$5)
- **USB Cable** (~$3)

### Software
- **Arduino IDE** (Free)
- **Python 3** (for image converter)

---

## 🔌 Pin Connections

<div align="center">

| ESP32 Pin | TFT Pin | Wire Color | Description |
|-----------|---------|------------|-------------|
| **GPIO 36** | **T_IRQ** | 🟡 Yellow | Touch Interrupt *(Optional)* |
| **GPIO 39** | **T_OUT** | 🟠 Orange | Touch Data Out *(Optional)* |
| **GPIO 32** | **T_DIN** | 🔴 Red | Touch Data In *(Optional)* |
| **GPIO 33** | **T_CS** | 🟣 Purple | Touch Chip Select *(Optional)* |
| **GPIO 25** | **T_CLK** | 🔵 Blue | Touch Clock *(Optional)* |
| **GPIO 12** | **SDO (MISO)** | 🟢 Green | SPI Master In Slave Out |
| **GPIO 21** | **LED** | ⚪ White | Backlight Control |
| **GPIO 14** | **SCK** | 🟤 Brown | SPI Clock |
| **GPIO 13** | **SDI (MOSI)** | ⚫ Black | SPI Master Out Slave In |
| **GPIO 2** | **D/C** | 🔘 Gray | Data/Command |
| **EN/RESET** | **RESET** | 🟡 Yellow | Reset Pin |
| **GPIO 15** | **CS** | 🟠 Orange | Chip Select |
| **GND** | **GND** | ⚫ Black | Ground |
| **3.3V or 5V** | **VCC** | 🔴 Red | Power Supply |

**💡 Note:** Touch pins are optional - you can skip them if you only want image display!

</div>

---

## 🚀 Quick Start

### 1️⃣ Install Software
```bash
# Install Arduino IDE from arduino.cc
# Install ESP32 board package in Arduino IDE
# Install TFT_eSPI library
```

### 2️⃣ Connect Hardware
- Connect **essential pins** (SPI, power, D/C, CS, RESET)
- **Skip touch pins** if you don't need touch functionality
- Double-check all connections

### 3️⃣ Upload Code
```bash
# Open sketch_sep06c.ino in Arduino IDE
# Select ESP32 Dev Module board
# Click Upload
```

### 4️⃣ Enjoy! 🎉
Your display will show:
1. **Colored test rectangles** (2 seconds)
2. **Your image** in full-screen portrait mode
3. **"MY PICTURE!"** text overlay

---

## 🖼️ Display Your Own Images

### Method 1: Use the Included Converter ⭐

```bash
# Install Python PIL library
pip install Pillow

# Convert your image
python3 image_to_bitmap_converter.py your_image.jpg my_image

# Update Arduino code
#include "my_image_bitmap.h"
tft.pushImage(0, 0, my_image_bitmap_width, my_image_bitmap_height, my_image_bitmap);
```

### Method 2: Online Converter
- Use online image to C array converters
- Set format to RGB565
- Set dimensions to 320x480

---

## 🔧 Troubleshooting

<details>
<summary><b>🔍 Common Issues & Solutions</b></summary>

### Display shows nothing (black screen)
- ✅ Check power connections (VCC and GND)
- ✅ Verify all essential pin connections
- ✅ Check if backlight is working (LED pin)

### Display shows garbled colors
- ✅ Check SPI connections (SCK, MOSI, MISO)
- ✅ Verify D/C and CS pins
- ✅ Check TFT_eSPI library configuration

### Upload fails
- ✅ Use data cable, not charging cable
- ✅ Press and hold BOOT button while uploading
- ✅ Check COM port selection

### Image not displaying
- ✅ Verify image file is included correctly
- ✅ Check image dimensions (must be 320x480)
- ✅ Ensure bitmap format is correct

</details>

---

## 📊 Technical Specs

| Feature | Specification |
|---------|---------------|
| **Display Resolution** | 320x480 pixels |
| **Color Depth** | 16-bit RGB565 |
| **Image Format** | Bitmap (no compression) |
| **Memory Usage** | ~1.26MB for 320x480 image |
| **Touch Support** | Optional (wiring included) |
| **Power Supply** | 3.3V or 5V |

---

## 📁 Project Files

```
SPI-TFT-with-ESP32/
├── 📄 sketch_sep06c.ino              # Main Arduino code
├── 🖼️ MyPicture_bitmap.h             # Image data (1.26MB)
├── 📸 MyPicture.png                  # Source image
├── 📷 Output_Picture.jpg             # Actual display output
├── 🐍 image_to_bitmap_converter.py   # Image converter script
├── 📖 README.md                      # This documentation
└── 📄 LICENSE                        # MIT License
```

---

## 🎯 What You'll Learn

- ✅ **Electronics**: GPIO pins, SPI communication, power supply
- ✅ **Programming**: Arduino IDE, libraries, bitmaps
- ✅ **Hardware**: TFT displays, touchscreens, connections
- ✅ **Image Processing**: RGB565 format, bitmap conversion

---

## 🚀 Next Steps

- **Display different images** using the converter
- **Add touch functionality** (connect touch pins)
- **Create photo slideshow**
- **Add sensor data display**
- **Build a digital photo frame**

---

## 📞 Support & Contact

**Need help?** I'm here to assist!

- 📧 **Email**: [me@pappuraj.com](mailto:me@pappuraj.com)
- 🌐 **Website**: [pappuraj.com](https://pappuraj.com)
- 💼 **LinkedIn**: [linkedin.com/in/pappuraj](https://linkedin.com/in/pappuraj)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🙏 Acknowledgments

- **Bodmer** for TFT_eSPI library
- **Espressif** for ESP32 platform
- **Arduino** community for support

---

<div align="center">

**⭐ If this project helped you, please give it a star! ⭐**

**Happy coding! 🚀**

</div>