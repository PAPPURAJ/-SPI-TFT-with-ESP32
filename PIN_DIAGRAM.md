# SPI TFT with ESP32 Pin Connection Diagram

## 🔌 Visual Pin Layout

```
ESP32 Development Board          TFT LCD Touchscreen
┌─────────────────────┐         ┌─────────────────────┐
│ 3.3V  GND  GPIO21  │─────────│ VCC  GND  LED      │
│ GPIO36 GPIO39      │─────────│ T_IRQ T_OUT        │
│ GPIO32 GPIO33      │─────────│ T_DIN T_CS         │
│ GPIO25 GPIO12      │─────────│ T_CLK SDO(MISO)    │
│ GPIO14 GPIO13      │─────────│ SCK  SDI(MOSI)     │
│ GPIO2  GPIO15      │─────────│ D/C  CS            │
│ EN/RESET           │─────────│ RESET              │
└─────────────────────┘         └─────────────────────┘
```

## 📋 Detailed Pin Connections

| ESP32 Pin | TFT Pin | Wire Color | Description |
|-----------|---------|------------|-------------|
| **GPIO 36** | **T_IRQ** | 🟡 Yellow | Touch Interrupt |
| **GPIO 39** | **T_OUT** | 🟠 Orange | Touch Data Out |
| **GPIO 32** | **T_DIN** | 🔴 Red | Touch Data In |
| **GPIO 33** | **T_CS** | 🟣 Purple | Touch Chip Select |
| **GPIO 25** | **T_CLK** | 🔵 Blue | Touch Clock |
| **GPIO 12** | **SDO (MISO)** | 🟢 Green | SPI Master In Slave Out |
| **GPIO 21** | **LED** | ⚪ White | Backlight Control |
| **GPIO 14** | **SCK** | 🟤 Brown | SPI Clock |
| **GPIO 13** | **SDI (MOSI)** | ⚫ Black | SPI Master Out Slave In |
| **GPIO 2** | **D/C** | 🔘 Gray | Data/Command |
| **EN/RESET** | **RESET** | 🟡 Yellow | Reset Pin |
| **GPIO 15** | **CS** | 🟠 Orange | Chip Select |
| **GND** | **GND** | ⚫ Black | Ground |
| **3.3V or 5V** | **VCC** | 🔴 Red | Power Supply |

## ⚡ Power Supply Options

### Option 1: 3.3V (Recommended for beginners)
```
ESP32 3.3V ────────── TFT VCC
ESP32 GND  ────────── TFT GND
```

### Option 2: 5V (For displays requiring 5V)
```
ESP32 5V ──────────── TFT VCC
ESP32 GND ─────────── TFT GND
```

## 🔧 Connection Tips

1. **Use Dupont wires** for easy connections
2. **Color-code your wires** as shown in the table above
3. **Double-check connections** before powering on
4. **Secure connections** to prevent loose wires
5. **Keep wires short** to reduce interference

## 🚨 Safety Notes

- ⚠️ **Always power off** before making connections
- ⚠️ **Check voltage requirements** of your TFT display
- ⚠️ **Don't connect VCC to wrong voltage** (can damage display)
- ⚠️ **Ensure GND is connected** for proper operation

## 🔍 Testing Connections

After connecting, test with this simple code:

```cpp
void setup() {
  Serial.begin(115200);
  pinMode(21, OUTPUT);  // LED pin
  digitalWrite(21, HIGH);  // Turn on backlight
  Serial.println("Connections test - backlight should be ON");
}

void loop() {
  // Test code here
}
```

## 📱 Display Orientation

The display can be rotated in software:

```cpp
tft.setRotation(0);  // Portrait (320x480)
tft.setRotation(1);  // Landscape (480x320)
tft.setRotation(2);  // Portrait upside down
tft.setRotation(3);  // Landscape upside down
```

## 🎯 Quick Start Checklist

- [ ] ESP32 board ready
- [ ] TFT display ready
- [ ] Dupont wires prepared
- [ ] Power supply checked (3.3V or 5V)
- [ ] All 15 connections made
- [ ] Connections double-checked
- [ ] Arduino IDE configured
- [ ] Libraries installed
- [ ] Code uploaded
- [ ] Display working!

---

**Need help?** Check the main README.md for detailed troubleshooting steps.
