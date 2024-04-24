/*
  BM1422AGMV Compass Sensor Reading and Heading Calculation
  This Arduino sketch is designed to interface with the BM1422AGMV compass sensor using the I2C communication protocol.
  It initializes the sensor, reads the magnetic field measurements along the X and Y axes, and calculates the heading.

  The heading is calculated based on the arctangent of the Y and X magnetic field values, converted from radians to degrees.
  If the calculated heading is negative, it is adjusted by adding 360 degrees to ensure it falls within the range of 0.0 to 359.9 degrees.
  This value represents the angle in degrees from North, rotating clockwise.

  Dependencies:
  - Wire library for I2C communication.

  Hardware Connections:
  - Connect the SDA and SCL pins of the sensor to the respective SDA and SCL pins on the Arduino.
  - Ensure the sensor is powered with the correct voltage as per its specifications.

  Note: This sketch outputs the heading to the Serial Monitor in degrees, rounded to one decimal place.
*/

/*
  BM1422AGMV コンパスセンサー読取りおよび方位計算
  このArduinoスケッチは、I2C通信プロトコルを使用してBM1422AGMVコンパスセンサーとのインターフェースを実現します。
  センサーを初期化し、X軸とY軸に沿った地磁気の測定値を読み取り、方位（ヘディング）を計算します。

  方位は、Y軸とX軸の地磁気値のアークタンジェントに基づいて計算され、ラジアンから度に変換されます。
  計算された方位が負の場合は、360度を加えて0.0度から359.9度の範囲に調整されます。
  この値は、北を基準として時計回りの角度（度）として表されます。

  依存関係:
  - I2C通信のためのWireライブラリ。

  ハードウェア接続:
  - センサーのSDAおよびSCLピンをArduinoの対応するSDAおよびSCLピンに接続します。
  - センサーが仕様に基づいた正しい電圧で動作するようにしてください。

  注意: このスケッチは方位をシリアルモニターに度単位で出力し、小数点以下1桁で丸められます。
*/


#include <Wire.h>
#include <math.h>

// BM1422AGMV I2C address
#define SENSOR_I2C_ADDRESS 0x0C

// BM1422AGMV Register addresses
#define INFO 0x0D
#define DATAX 0x10

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize the compass sensor
  Wire.beginTransmission(SENSOR_I2C_ADDRESS);
  Wire.write(INFO);       // Register to write to
  Wire.write(0x80);       // Command to reset the sensor
  Wire.endTransmission();

  delay(10);              // Wait for the reset to complete

  Wire.beginTransmission(SENSOR_I2C_ADDRESS);
  Wire.write(INFO);
  Wire.write(0x00);       // Normal mode operation
  Wire.endTransmission();
}

void loop() {
  int x, y;

  Wire.beginTransmission(SENSOR_I2C_ADDRESS);
  Wire.write(DATAX);  // Address of the data register
  Wire.endTransmission(false);

  Wire.requestFrom(SENSOR_I2C_ADDRESS, 6); // Request 6 bytes, 2 bytes each for X, Y, Z
  if (Wire.available() == 6) {
    x = Wire.read() | (Wire.read() << 8);   // Read X axis data
    y = Wire.read() | (Wire.read() << 8);   // Read Y axis data
    // Z-axis data is read but not used in this example
    Wire.read(); Wire.read();

    // Calculate heading
    float heading = atan2((float)y, (float)x) * 180.0 / PI;
    if (heading < 0) {
      heading += 360.0; // Correct for when the angle is negative
    }

    // Print heading
    Serial.print("Heading: ");
    Serial.print(heading, 1);  // Display one decimal place
    Serial.println(" degrees");
  }

  delay(1000);  // Delay for 1 second before next reading
}
