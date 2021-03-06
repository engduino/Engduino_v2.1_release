void level() {
  // Accelerometer demo - level
  //
  // Show a red LED on one side if we're low on that side
  // show nothing if we're high, and show green on both sides
  // if it's level(ish)
  //
  // We delay between readings because it's a bit flashy
  // otherwise - too hard to hold steady
  //

  while (true)
  { float xyz[3];
  
    // Read the acceleration
    //
    EngduinoAccelerometer.xyz(xyz);
    
    // And light the appropriate LEDs depending on whether we're level
    // or not. The LEDs chosen are on opposite sides of the board.
    //
    if ((xyz[0] > 0 && xyz[0] < 0.02) || (xyz[0] < 0 && xyz[0] > -0.02)) {
      EngduinoLEDs.setLED(11, GREEN);
      EngduinoLEDs.setLED( 3, GREEN);
    }
    else if (xyz[0] > 0.02) {
      EngduinoLEDs.setLED(11, RED);
      EngduinoLEDs.setLED( 3, OFF);    
    }
    else {
      EngduinoLEDs.setLED(11, OFF);
      EngduinoLEDs.setLED( 3, RED);
    }
    
    if ((xyz[1] > 0 && xyz[1] < 0.02) || (xyz[1] < 0 && xyz[1] > -0.02)) {
      EngduinoLEDs.setLED( 8, GREEN);
      EngduinoLEDs.setLED(14, GREEN);
    }
    else if (xyz[1] > 0.02) {
      EngduinoLEDs.setLED( 8, RED);
      EngduinoLEDs.setLED(14, OFF);    
    }
    else {
      EngduinoLEDs.setLED( 8, OFF);
      EngduinoLEDs.setLED(14, RED);
    }
    
    // Wait 50ms, then loop
    //
    delay(50);
  }
}
