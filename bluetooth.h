

#include <BluetoothSerial.h>



#define maxChar 32
char message[maxChar];
char readChar;
byte index1 = 0;
int i;

BluetoothSerial SerialBT;



void processBluetoothCommand(char command) {

  Serial.println(command);

  switch (command) {
    case '0':
      digitalWrite(LED_BUILTIN, 0);
      clockwise = false;
      anticlockwise = false;

      break;
    case 'n':
      digitalWrite(LED_BUILTIN, 1);

      break;
    case 'N':
      clockwise = true;
      break;
    case 'S':
      anticlockwise = true;

      break;
  }
}
void messageBluetoothCommand() {

  if (SerialBT.available()) {
    for (i = 0; i < 31; i++) {
      message[i] = '\0';
    }
    index1 = 0;
  }
  while (SerialBT.available() > 0) {
    if (index1 < (maxChar - 1)) {
      readChar = SerialBT.read();
      message[index1] = readChar;
      index1++;
      message[index1] = '\0';
    }
  }
  Serial.print(message);
}
void BTloop() {

  if (SerialBT.available()) {
    processBluetoothCommand(SerialBT.read());
  } else if (SerialBT.available()) {
    messageBluetoothCommand();
    Serial.println(SerialBT.read());
  }
}
