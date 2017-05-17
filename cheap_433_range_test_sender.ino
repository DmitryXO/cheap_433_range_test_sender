#include <VirtualWire.h>

#define LED_PIN 13

uint8_t counter = 0; 

void setup() {
    vw_set_tx_pin(12);
    vw_set_rx_pin(11);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(1000); // Bits per sec
    pinMode(LED_PIN, OUTPUT);
}

void loop() {

  char msg[1];

  msg[0] = counter;

  vw_send((uint8_t *)msg, 1);
  vw_wait_tx(); // Wait until the whole message is gone

  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
  delay(50);
  
  counter++;
}
