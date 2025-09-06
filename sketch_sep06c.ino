#include <SPI.h>
#include <TFT_eSPI.h>
#include <TJpg_Decoder.h>
#include "MyPicture_bitmap.h"   // MyPicture_bitmap[], MyPicture_bitmap_width, MyPicture_bitmap_height

TFT_eSPI tft;

bool tft_output(int16_t x,int16_t y,uint16_t w,uint16_t h,uint16_t* bmp){
  static int call_count = 0;
  call_count++;
  
  if (y >= tft.height()) {
    Serial.printf("Callback: y=%d >= height=%d, stopping\n", y, tft.height());
    return false;
  }
  
  if (call_count <= 5) {  // Log first 5 calls
    Serial.printf("Callback %d: x=%d, y=%d, w=%d, h=%d\n", call_count, x, y, w, h);
  }
  
  tft.pushImage(x,y,w,h,bmp);
  return true;
}

void setup() {
  Serial.begin(115200);
  delay(1000);  // Give time for serial to initialize
  Serial.println("Starting ESP32 TFT Display Test...");
  
  tft.init();
  tft.setRotation(0);  // Portrait mode for best fit with 320x480 image
  tft.setSwapBytes(true);   // important
  tft.fillScreen(TFT_BLACK);
  Serial.printf("TFT initialized in portrait mode: %dx%d pixels\n", tft.width(), tft.height());
  Serial.println("TFT initialized and screen cleared");
  
  // Test TFT display with colored rectangles
  Serial.println("Testing TFT display...");
  tft.fillRect(10, 10, 50, 30, TFT_RED);
  tft.fillRect(70, 10, 50, 30, TFT_GREEN);
  tft.fillRect(130, 10, 50, 30, TFT_BLUE);
  delay(2000);  // Show test colors for 2 seconds
  tft.fillScreen(TFT_BLACK);
  Serial.println("TFT test completed");

  // Test with your picture as bitmap (no JPEG decoder)
  Serial.println("Testing your picture as bitmap...");
  Serial.printf("Image size: %dx%d pixels\n", MyPicture_bitmap_width, MyPicture_bitmap_height);
  
  // Display portrait full screen (320x480 on portrait display)
  Serial.printf("Portrait full screen image: %dx%d pixels\n", MyPicture_bitmap_width, MyPicture_bitmap_height);
  Serial.printf("Display size in portrait mode: %dx%d pixels\n", tft.width(), tft.height());
  
  // Draw your picture at (0,0) for perfect full screen fit
  tft.pushImage(0, 0, MyPicture_bitmap_width, MyPicture_bitmap_height, MyPicture_bitmap);
  
  Serial.println("Your picture drawing completed!");
  
  // Add some text
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("MY PICTURE!", 10, 10);
  tft.drawString("320x480 image", 10, 30);
  tft.drawString("Portrait Display", 10, 50);
}
void loop() {}
