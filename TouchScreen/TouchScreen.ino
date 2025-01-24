#include <TouchScreen.h>

// Touchscreen pin definitions
#define YP A2 // Y+ connected to A2
#define XM A0 // X- connected to A0
#define YM A1 // Y- connected to A1
#define XP A3 // X+ connected to A3

// Calibration values (adjust based on your screen)
#define TS_MINX 150
#define TS_MAXX 920
#define TS_MINY 120
#define TS_MAXY 940

// Define screen dimensions
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

// Create a TouchScreen object
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() {
  Serial.begin(9600);
  Serial.println("Touchscreen Test");
}

void loop() {
  TSPoint p = ts.getPoint(); // Get touch coordinates


  // Map raw touch coordinates to screen dimensions
  int x = map(p.x, TS_MINX, TS_MAXX, 0, SCREEN_WIDTH);
  int y = map(p.y, TS_MINY, TS_MAXY, 0, SCREEN_HEIGHT);

  // Print the touch coordinates
  Serial.print("X = ");
  Serial.print(x);
  Serial.print(", Y = ");
  Serial.println(y);

  delay(100); // Small delay for stability
}
