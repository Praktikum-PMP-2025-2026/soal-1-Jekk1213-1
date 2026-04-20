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
            int kiri = -1;
            int kanan = -1;
            int indexKiri = -1; 
            int indexKanan = -1;

            // Cari tetangga kiri
            for (int j=i-1; j>=0; j--) {
                if (awal[j]!=-1) {
                    kiri=awal[j];
                    indexKiri=j;
                    break;
                }
            }

            // Cari tetangga kanan
            for (int j=i+1; j<n; j++) {
                if (awal[j]!=-1) {
                    kanan=awal[j];
                    indexKanan=j;
                    break;
                }
            }


            //logika penggantian -1 dan lain lainnya 
            if (indexKiri!=-1 && indexKanan!=-1) {
                //jarak ke kiri dan ke kanan
                int distKiri=i-indexKiri;
                int distKanan=indexKanan-i;

                if (distKanan<distKiri) {
                    //lebih dekat ke kanan, ambil nilai kanan langsung
                    recov[i]=kanan;
                } else {
                    //lebih dekat ke kiri atau tepat di tengah, ambil median
                    recov[i]=(kiri + kanan)/2;
                }
            } 
            else if (indexKiri!=-1) {
                recov[i]=kiri;
            } 
            else if (indexKanan!=-1) {
                recov[i]=kanan;
            } 
            else {
                recov[i]=0;
            }

        }
    }

    //tampilkan hasil RECOVERED
    printf("RECOVERED");
    for (int i=0; i<n; i++) {
        printf(" %d", recov[i]);
    }

    //hitung Max Subarray Sum
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
        printf("\nMAX_SUM %d ", sumMax);
    }
    return 0;
}
