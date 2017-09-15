#include <stdint.h>
#include <stdbool.h>
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

void setup() {
    Serial.begin(9600);
    nfc.begin();
}

void loop() {
    Serial.println("\nPlace NFC Tag");
    if (nfc.tagPresent()) {
        NdefMessage message = NdefMessage();
        message.addTextRecord("Que pedo eh?");
        message.addTextRecord("Comete un pan");
        //message.addUriRecord("https://google.com");
        boolean success = nfc.write(message);
        if (success) {
            Serial.println("Write Success");
        } else {
            Serial.println("Write Failed");
        }
    }
    delay(10000);
}
