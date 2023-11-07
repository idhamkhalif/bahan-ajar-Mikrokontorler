#include <Arduino.h>
#include "FS.h"
#include "SPIFFS.h"

void setup() {
  Serial.begin(115200);
  if (!SPIFFS.begin(true)) {
    Serial.println("Gagal menginisialisasi SPIFFS");
    return;
  }

  // Menulis data ke SPIFFS
  writeData();

  // Membaca dan menampilkan data dari SPIFFS
  readData();
}

void writeData() {
  File file = SPIFFS.open("/data.txt", "w");
  if (!file) {
    Serial.println("Gagal membuka berkas untuk menulis");
    return;
  }

  // Menulis data ke berkas
  String dataToWrite = "Ini adalah contoh data yang akan disimpan di SPIFFS.";
  file.println(dataToWrite);

  // Menutup berkas
  file.close();
  Serial.println("Data ditulis ke SPIFFS");
}

void readData() {
  File file = SPIFFS.open("/data.txt", "r");
  if (!file) {
    Serial.println("Gagal membuka berkas untuk membaca");
    return;
  }

  // Membaca dan menampilkan isi berkas
  while (file.available()) {
    Serial.write(file.read());
  }
  Serial.println(); // Baris baru

  // Menutup berkas
  file.close();
}

void loop() {
  // Kode lainnya di sini
}
