/***************************************************************
  This is a call backfunction. Whenever the I2C sends data,
  this function will be run.
****************************************************************/
void receiveData(int byteCount) {
  int i = 0;
  while (Wire.available()) {
    dataReceived = Wire.read();
  }
  

}


/***************************************************************
  This is a call backfunction. Whenever the I2C master requests
  a data transfer, this function will be run.
****************************************************************/
void sendData() {

  Wire.write(dataQueued);
  Serial.println(dataQueued);
}




void voltageRead() {
  int sensorValueOne = analogRead(POWER_PIN_1);
  Wire.write(sensorValueOne);
  Serial.println(sensorValueOne);

  int sensorValueTwo = analogRead(POWER_PIN_2);
  Wire.write(sensorValueTwo);
  Serial.println(sensorValueTwo);
}

