# BM1422AGMV-Compass
BM1422AGMV
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
