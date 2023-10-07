// ประกาศตัวแปร lastHighTime และ lastLowTime เพื่อเก็บเวลาล่าสุดที่ไฟเป็นสถานะ HIGH และ LOW
unsigned long lastHighTime = 0;
unsigned long lastLowTime = 0;

// ฟังก์ชัน setup จะทำงานครั้งเดียวเมื่อเริ่มต้นโปรแกรม
void setup() {
  pinMode(9, OUTPUT); // ตั้งขา 9 ให้เป็น OUTPUT
  digitalWrite(9, LOW); // ตั้งขา 9 ให้เป็น LOW หรือปิดไฟ
  Serial.begin(9600); // เริ่มต้น Serial ที่ความเร็ว 9600 bps
}

// ฟังก์ชัน loop จะทำงานซ้ำ ๆ ตลอดเวลา
void loop() {
  unsigned long currentTime = millis(); // รับเวลาปัจจุบันในหน่วยมิลลิวินาที

  // ตรวจสอบสถานะปัจจุบันของขา 9 ว่าเป็น HIGH หรือไม่
  if (digitalRead(9) == HIGH) {
    // ถ้าเวลาปัจจุบัน - เวลาที่ไฟเป็นสถานะ HIGH ล่าสุด >= 3000 มิลลิวินาที
    if (currentTime - lastHighTime >= 3000) {
      digitalWrite(9, LOW); // ตั้งขา 9 ให้เป็น LOW หรือปิดไฟ
      Serial.println("Status: Dark"); // แสดงข้อความ "Status: Dark" ใน Serial Monitor
      lastLowTime = currentTime; // อัปเดตเวลาที่ไฟเป็นสถานะ LOW ล่าสุด
    }
  } else {
    // ถ้าเวลาปัจจุบัน - เวลาที่ไฟเป็นสถานะ LOW ล่าสุด >= 1000 มิลลิวินาที
    if (currentTime - lastLowTime >= 1000) {
      digitalWrite(9, HIGH); // ตั้งขา 9 ให้เป็น HIGH หรือเปิดไฟ
      Serial.println("Status: Light"); // แสดงข้อความ "Status: Light" ใน Serial Monitor
      lastHighTime = currentTime; // อัปเดตเวลาที่ไฟเป็นสถานะ HIGH ล่าสุด
    }
  }
}