#include <Arduino.h>
#include <Servo.h>
#include <unity.h>

void setUp(void) {
// set stuff up here
}

void tearDown(void) {
// clean stuff up here
}

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_state_high(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void) {
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

int outPorts[] = {11, 10, 9, 8};

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

   for (int i = 0; i < 4; i++) 
    {
        pinMode(outPorts[i], OUTPUT);

    }
    UNITY_BEGIN();    // IMPORTANT LINE!
    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;




void moveOneStep(bool dir) ;
void moveSteps(bool dir, int steps, byte ms) ;
void loop()
{   
    test_led_state_high();
    moveSteps(true, 32 * 64, 2);
    delay(500);
    test_led_state_low();
    moveSteps(false, 32 * 64, 2);
    delay(500);
}

void moveSteps(bool dir, int steps, byte ms) {
 for (int i = 0; i < steps; i++) {
    moveOneStep(dir); // Rotate a step
    delay(ms);
//  // Control the speed
}
}
void moveOneStep(bool dir) {
 // Define a variable, use four low bit to indicate the state of port
static byte out = 0x01;
 // Decide the shift direction according to the rotation direction
  if (dir) {
 // ring shift left

 out != 0x08 ? out = out << 1 : out = 0x01;

  }
 else {
 // ring shift right
   out != 0x01 ? out = out >> 1 : out = 0x08;
 }

 // Output singal to each port

 for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
 }
}