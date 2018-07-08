/***************************************************************
  This is a call backfunction. Whenever the I2C sends data,
  this function will be run.
****************************************************************/
void receiveData(int byteCount) {

  while (Wire.available()) {
    dataReceived = Wire.read();
    Serial.print("data received: ");
    Serial.println(dataReceived);
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