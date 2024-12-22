import time
import sys
import matplotlib.pyplot as plt

# Set batas rekursi lebih tinggi
sys.setrecursionlimit(200000)

# Definisi class Karyawan
class Karyawan:
    def __init__(self, nama, jabatan):
        self.nama = nama
        self.jabatan = jabatan

# Fungsi untuk menghitung gaji manual
def hitung_gaji_manual(jabatan, faktor):
    if jabatan == "Manager":
        return 10000000 * faktor
    elif jabatan == "Staff":
        return 5000000 * faktor
    elif jabatan == "Engineer":
        return 8000000 * faktor
    else:
        return 3000000 * faktor

# Iteratif
def cari_nama_iteratif(nama, karyawan):
    for k in karyawan:
        if k.nama == nama:
            return hitung_gaji_manual(k.jabatan, 1)
    return -1

# Rekursif
def cari_nama_rekursif(nama, karyawan, index):
    if index >= len(karyawan):
        return -1
    if karyawan[index].nama == nama:
        return hitung_gaji_manual(karyawan[index].jabatan, 1)
    return cari_nama_rekursif(nama, karyawan, index + 1)

def cari_nama_rekursif_wrapper(nama, karyawan):
    return cari_nama_rekursif(nama, karyawan, 0)

# Fungsi untuk mengukur waktu eksekusi
def ukur_waktu(fungsi, *args, ulang=5):
    waktu = []
    for _ in range(ulang):
        start = time.perf_counter()
        fungsi(*args)
        waktu.append(time.perf_counter() - start)
    return sum(waktu) / ulang

# Fungsi untuk membuat grafik
def plot_graph(data_sizes, iter_times, recur_times):
    plt.figure(figsize=(10, 5))
    plt.plot(data_sizes, iter_times, label="Iteratif")
    plt.plot(data_sizes, recur_times, label="Rekursif")
    plt.title("Perbandingan Waktu Iteratif vs Rekursif")
    plt.xlabel("Jumlah Karyawan")
    plt.ylabel("Waktu Eksekusi (detik)")
    plt.legend()
    plt.grid()
    plt.savefig("execution_time_comparison.png")
    plt.show()

# Fungsi untuk menampilkan hasil pencarian dalam bentuk tabel
def print_search_table(nama, hasil_iter, durasi_iter, hasil_recur, durasi_recur):
    print("\nHasil Pencarian:")
    print("------------------------------------------------------------")
    print(f"{'Metode':<10} | {'Hasil Gaji':>10} | {'Waktu Eksekusi (s)':>20}")
    print("------------------------------------------------------------")
    print(f"{'Iteratif':<10} | {hasil_iter:>10} | {durasi_iter:>20.8f}")
    print(f"{'Rekursif':<10} | {hasil_recur:>10} | {durasi_recur:>20.8f}")
    print("------------------------------------------------------------")

# Fungsi utama
def main():
    # Dataset karyawan dengan jumlah besar
    karyawan = []
    for i in range(1500000):
        jabatan = "Staff"
        if i % 3 == 0:
            jabatan = "Manager"
        elif i % 3 == 1:
            jabatan = "Engineer"
        karyawan.append(Karyawan(f"Nama{i+1}", jabatan))

    iter_times = []
    recur_times = []
    data_sizes = []

    while True:
        print("\nMenu:")
        print("1. Tampilkan Data Karyawan (Hanya 10 Data Pertama)")
        print("2. Cari Karyawan (Perbandingan Iteratif vs Rekursif)")
        print("3. Bandingkan Waktu dengan Grafik")
        print("4. Keluar")
        pilihan = int(input("Pilihan: "))

        if pilihan == 1:
            print("10 Data Karyawan Pertama:")
            for i in range(10):
                print(f"Nama: {karyawan[i].nama}, Jabatan: {karyawan[i].jabatan}")
        elif pilihan == 2:
            nama = input("Masukkan nama karyawan yang dicari: ")

            # Hitung waktu eksekusi
            durasi_iter = ukur_waktu(cari_nama_iteratif, nama, karyawan)
            durasi_recur = ukur_waktu(cari_nama_rekursif_wrapper, nama, karyawan)

            # Cari gaji
            hasil_iter = cari_nama_iteratif(nama, karyawan)
            hasil_recur = cari_nama_rekursif_wrapper(nama, karyawan)

            # Tampilkan hasil pencarian dalam bentuk tabel
            if hasil_iter == -1 and hasil_recur == -1:
                print("Karyawan tidak ditemukan.")
            else:
                print_search_table(nama, hasil_iter, durasi_iter, hasil_recur, durasi_recur)

        elif pilihan == 3:
            # Simulasi waktu eksekusi dengan subset data
            for n in range(100000, 1500001, 100000):
                subset = karyawan[:n]

                iter_times.append(ukur_waktu(cari_nama_iteratif, "Nama1000", subset))
                recur_times.append(ukur_waktu(cari_nama_rekursif_wrapper, "Nama1000", subset))
                data_sizes.append(n)

            plot_graph(data_sizes, iter_times, recur_times)
            print("Grafik telah disimpan sebagai 'execution_time_comparison.png'.")
        elif pilihan == 4:
            print("Keluar program.")
            break
        else:
            print("Pilihan tidak valid.")

if __name__ == "__main__":
    main()
