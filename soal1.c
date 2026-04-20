#include <stdio.h>

int main() {
    int awal[100];
    int recov[100];
    int n = 0;
    int jumlahInput;

    //inputnya, ambil angka pertama sebagai jumlahnya
    if (scanf("%d", &jumlahInput) !=1) {
        return 0; // Berhenti jika tidak ada input
    }

    for (int i=0; i<jumlahInput; i++) {
        if (scanf("%d", &awal[n])==1) {
            n++;
        }
    }

    //bagian geser geser dan recovery
    for (int i=0; i<n; i++) {
        if (awal[i]!=-1) {
            recov[i]=awal[i];
        } 
        
        else {
            int kiri=-1;
            int kanan=-1;
            int masukkiri=0;
            int masukkanan=0;

            //cara tetangga dari kiri
            for (int j=i-1; j>=0; j--) {
                if (awal[j]!=-1) {
                    kiri=awal[j];
                    masukkiri=1;
                    break;
                }
            }

            //cari tetangga valid terdekat di kanan
            for (int j=i+1; j<n; j++) {
                if (awal[j]!=-1) {
                    kanan=awal[j];
                    masukkanan=1;
                    break;
                }
            }

            //logika penggantian -1 dan lain lainnya 
            if (masukkiri && masukkanan) {
                recov[i]=(kiri+kanan)/2; //mediannya
            } 
            else if (masukkiri) {
                recov[i]=kiri;
            } 
            else if (masukkanan) {
                recov[i]=kanan;
            } 
            else {
                recov[i]=0;
            }
        }
    }

    // Tampilkan hasil RECOVERED
    printf("RECOVERED \n");
    for (int i=0; i<n; i++) {
        printf("%d ", recov[i]);
    }

    // 3. Hitung Max Subarray Sum
    if (n>0) {
        int sumMax = recov[0];
        int sumBaru = recov[0];

        for (int i=1; i<n; i++) {
            //logika logika Sum
            if (recov[i]>sumBaru+recov[i]) {
                sumBaru=recov[i];
            } else {
                sumBaru=sumBaru+recov[i];
            }

            if (sumBaru>sumMax) {
                sumMax=sumBaru;
            }
        }
        printf("\nMAX_SUM %d\n", sumMax);
    }
    return 0;
}
