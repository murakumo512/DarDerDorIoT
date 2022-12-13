import mysql.connector
import os
import time
import datetime

db = mysql.connector.connect(
  host="localhost",
  user="riel",
  passwd="qwe123",
  database="theacantik"
)


def insert_data(db):
  name = input("Masukan nama: ")
  val = [(name)]
  timestamp="NOW()"
  cursor = db.cursor()
  sql = "insert into test (jarak) values (%s)"
  cursor.execute(sql, val,timestamp)
  db.commit()
  print("{} data berhasil disimpan".format(cursor.rowcount))
  show_menu(db)

  `{msg.payload.decode()}`


def show_data(db):
  cursor = db.cursor()
  sql = "SELECT * FROM test"
  cursor.execute(sql)
  results = cursor.fetchall()
  
  if cursor.rowcount < 0:
    print("Tidak ada data")
  else:
    for data in results:
      print(data)
  print()
  show_menu(db)


def show_menu(db):
  print("=== APLIKASI DATABASE PYTHON ===")
  print("1. Insert Data")
  print("2. Tampilkan Data")
  print("---show_menu(db)---------------")
  menu = input("Pilih menu> ")
  

  #clear screen
  os.system("clear")

  if menu == "1":
    insert_data(db)
  elif menu == "2":
    show_data(db)
    exit()
  else:
    print("Menu salah!")


if __name__ == "__main__":
  while(True):
    show_menu(db)