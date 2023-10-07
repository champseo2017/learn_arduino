// ประกาศตัวแปรชื่อ 'Echo' ที่มีชนิดข้อมูลเป็น 'byte'
// 'Echo' เป็นชื่อของตัวแปรที่สามารถถูกใช้เก็บข้อมูลแบบ byte (0-255)
byte Echo;

// ฟังก์ชัน setup() จะถูกเรียกเมื่อโปรแกรมเริ่มทำงาน
void setup()
{
  // ตั้งค่าขา 13 เป็น OUTPUT (เอาท์พุต)
  pinMode(13, OUTPUT);

  // ตั้งสถานะขา 13 เป็น LOW (ปิดไฟ)
  digitalWrite(13, LOW);

  // เริ่มการสื่อสารผ่าน Serial port ที่ความเร็ว 9600 bits per second
  Serial.begin(9600);
}

// ฟังก์ชัน loop() จะถูกเรียกซ้ำๆ เมื่อ setup() เสร็จสิ้น
void loop()
{
  // ตั้งสถานะขา 13 เป็น HIGH (เปิดไฟ)
  digitalWrite(13, HIGH);

  // ส่งข้อความ "Status: Light" ไปยัง Serial port
  Serial.println("Status: Light");

  // หน่วงเวลา 3000 มิลลิวินาที (3 วินาที)
  delay(3000);

  // ตั้งสถานะขา 13 เป็น LOW (ปิดไฟ)
  digitalWrite(13, LOW);

  // ส่งข้อความ "Status: Dark" ไปยัง Serial port
  Serial.println("Status: Dark");

  // หน่วงเวลา 1000 มิลลิวินาที (1 วินาที)
  delay(1000);
}
