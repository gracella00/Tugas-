class Motor:
    def ___init___(self, merk, harga, stok):
        self.merk = merk
        self.harga = harga
        self.stok = stok

    def tampilkan_info(self):
        print(f"Merk: {self.merk}, Harga: {self.harga} USD, Stok: {self.stok} unit")

def beli_motor(motor, jumlah):
    if motor.stok >= jumlah:
        total_harga = motor.harga * jumlah
        motor.stok -= jumlah
        return f"Anda telah membeli {jumlah} unit {motor.merk}. Total harga: {total_harga} USD."
    else:
        return f"Maaf, stok {motor.merk} tidak mencukupi untuk pembelian ini."

def main():
    daftar_motor = [
        Motor("Honda", 2000, 10),
        Motor("Yamaha", 1800, 15),
        Motor("Suzuki", 2200, 8),
        Motor("Ducati", 2001, 9)
    ]

    while True:
        print("\nMenu:")
        print("1. Tampilkan Motor")
        print("2. Beli Motor")
        print("3. Keluar")

        pilihan = input("Pilih menu (1/2/3): ")

        if pilihan == "1":
            print("\nDaftar Motor:")
            for motor in daftar_motor:
                motor.tampilkan_info()
        elif pilihan == "2":
            merk_motor = input("Masukkan merk motor yang ingin dibeli: ")
            motor_terpilih = next((motor for motor in daftar_motor if motor.merk.lower() == merk_motor.lower()), None)

            if motor_terpilih:
                jumlah_pembelian = int(input(f"Masukkan jumlah {motor_terpilih.merk} yang ingin dibeli: "))
                hasil_pembelian = beli_motor(motor_terpilih, jumlah_pembelian)
                print(hasil_pembelian)
            else:
                print("Merk motor tidak ditemukan.")
        elif pilihan == "3":
            print("Terima kasih! Keluar dari program.")
            break
        else:
            print("Pilihan tidak valid. Silakan pilih menu yang benar.")

if ___name___== "___main___":
    main()