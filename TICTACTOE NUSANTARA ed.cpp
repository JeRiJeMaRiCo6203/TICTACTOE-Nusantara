//Nusantara Tic Tac Toe
//Merayakan HUT RI yang ke-76
//By Jokemijean

#include <stdio.h>
#include <stdlib.h>
// pake stdlib untuk clear screen

char kotak[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
/* kenapa menampung 10 array? padahal kita hanya butuh dari 1-10
memang pada dasarnya kita hanya pake 9 angka. tapi karena array dimulai dari 0,
dan lebih mudah untuk penomoran sesuai dengan kotaknya. kita abaikan 0
untuk lebih jelas lihat bagian int main, do*/


//functions
int cekmenang(); // algoritma permainan
void papan(); //tampilan utama
/* karena board hanya untuk display dan tampilannya tetap sama,
kita pake void yang hanya print lalu selesai*/
void undian(); // lottery untuk pemenang 
void printArt(FILE *fp);
void delay();
int pemenang; 

int main() //pemain, pilihan
{ 
 int pemain = 1, i, pilihan;
 char tanda, answer = 'Y'; 
 

 FILE * fp = fopen("TICTACTOE title.txt", "r");
    printArt(fp);  
    printf("\n\n\nWELCOME TO TIC-TAC-TOE NUSANTARA!\n\n\n");
    delay();
    printf("Press enter to play the game!");
    getchar();
    system("@cls||clear");
    fclose(fp);

while(answer == 'Y'){
 do
 {
  papan();
  // pertama kita harus tampilin papannya dulu
  pemain = (pemain % 2) ? 1 : 2;
  /* jadi ada 2 pemain, pertama kita inisialisasi dengan 1. lalu 
  untuk menentukan kita pake mod*/
  
  printf("Pemain %d, masukkan angka:  ", pemain);
  scanf("%d", &pilihan);
  
  tanda = (pemain == 1)? 'X' : 'O';
  //untuk menandakan tanda masing2 pemain
  
  //Pilihan dan Tanda
  //pilihan dan kotak disamakan lalu diberi tanda pemain
  /* ada 9 pilihan jadi pake if - else if - else*/
  if (pilihan == 1 && kotak[1]== '1')
   kotak[1] = tanda;
  
  else if(pilihan == 2 && kotak [2] == '2')
   kotak[2] = tanda;
  
  else if(pilihan == 3 && kotak [3] == '3')
   kotak[3] = tanda;

  else if(pilihan == 4 && kotak [4] == '4')
   kotak[4] = tanda;

  else if(pilihan == 5 && kotak [5] == '5')
   kotak[5] = tanda;
   
  else if(pilihan == 6 && kotak [6] == '6')
   kotak[6] = tanda;

  else if(pilihan == 7 && kotak [7] == '7')
   kotak[7] = tanda;

  else if(pilihan == 8 && kotak [8] == '8')
   kotak[8] = tanda;

  else if(pilihan == 9 && kotak [9] == '9')
   kotak[9] = tanda; 
   
  else{
   printf("Angka sudah dipilih");
   
   pemain--;
   getchar();
   
   /*karena logika setelah ini adalah giliran pemain selanjutnya, tapi karena
   pemain input angka yang sudah ditandai, otomatis kita akan post decrement pemain
   jadi habis fungsi else selesai
   nanti ada pemain++, nah itu kayak -1 + 1 = 0, gak nambah,
   jadi pemain tadi pilih ulang sebuah angka*/
  }      
  i = cekmenang(); 
  /*kita harus periksa seiring gamenya berjalan apakah sudah ada pemain
  yang memenuhi syarat untuk menang*/
  
  
   pemain++; //giliran player selanjutnya
  //walaupun player 2 hbs itu ditambah jadi 3 tp 3 mod 2 ttp 1
  
 }
 while (i == -1); // do while -1, ketika game masih berjalan 
 
 papan();
 
 if (i == 1)
 {
  pemenang = --pemain;
  printf("~~~~>Pemain %d MENANG! \n", pemenang);
  undian();  
 }
 
 /*karena tadi kita player++ tapi habis dapat hasil fungsi papan
 kita --pemain saat itu juga*/
 
 else
 {
  printf("~~~~>Permainan Berakhir Seri!\n");
 }
// getchar();
// system("@cls||clear");

	 printf("Apakah anda ingin bermain lagi? (Y/N) \n");
	 	answer = 'N';
		scanf("%c",&answer);
	    if(answer == 'Y'){
	    pemain=1;
	    for (int x=1;x<=10;x++)
	    	kotak[x] = x+'0';
	    system("@cls||clear");
		}
}
 return 0;
}

/*********ARTI MASING-MASING FUNGSI RETURN*********
1 = Permainan telah berakhir
-1 = Permainan masih berjalan 
0 = Permainan selesai dan tidak ada hasil (seri)
**************************************************/

int cekmenang() //return sama kotak 
{ 
 /*syarat untuk menang adalah 3 tanda yang sama dalam baris
 horizontal, vertikal, ataupun diagonal. jadi kita sertakan semua syaratnya*/
 //indikator tandanya sudah sama (ref baris 46)
 //ada 8 kemungkinan
 
 //horizontal
 if(kotak[1] == kotak[2] && kotak[2] == kotak[3])
  return 1;
 
 else if (kotak[4] == kotak[5] && kotak[5] == kotak[6])
  return 1;
 
 else if (kotak[4] == kotak[5] && kotak[5] == kotak[6])
  return 1;
  
 else if (kotak[4] == kotak[5] && kotak[5] == kotak[6])
  return 1;
  
 //vertikal
 else if (kotak[1] == kotak[4] && kotak[4] == kotak[7])
  return 1;
  
 else if (kotak[2] == kotak[5] && kotak[5]== kotak[8])
  return 1;
  
 else if (kotak[3] == kotak[6] && kotak[6]== kotak[9])
  return 1; 
  
 //diagonal
 else if (kotak[1] == kotak[5] && kotak[5]== kotak[9])
  return 1;
  
 else if (kotak[3] == kotak[5] && kotak[5]== kotak[7])
  return 1;   
  
 //syarat seri(?)
 else if(kotak[1] != '1' && kotak[2] != '2' && kotak[3] != '3'
  && kotak[4] != '4' && kotak[5] != '5' && kotak[6] != '6' &&
  kotak[7] != '7' && kotak[8] != '8' && kotak[9] != '9')
  
   return 0;
 
 //lanjutkan permainan  
 else
  return -1;
}

/*TAMPILAN PAPAN NUSANTARA TIC TAC TOE*/

void papan()
{
 system("@cls||clear"); //untuk menghapus data papan sebelumnya (biar bersih dan gak curang)

 //judul game 
 printf("\n\n~~~~Nusantara Tic Tac Toe~~~~~~\n\n");
 printf(" !!Menuju HUT RI yang ke-76!!\n\n");
 printf(" Pemain 1 (X)  X  Pemain 2 (O)\n\n\n");
 
 //Papan
 //kenapa baris pertama sama kedua gak rapi, karena sebenarnya ukuran mereka sama
 /*setiap kotak terdiri dari 7 spasi (yg pertama tambah 2 untuk kerapian)
  nanti pas di print juga rapi. 1 karakter add 1 space*/
 
 printf("  =======|=======|=======\n");
 printf("         |       |       \n");
 printf("     %c   |   %c   |   %c     \n", kotak[1], kotak[2], kotak[3]); 
 printf("         |       |       \n");
 printf("  =======|=======|=======\n");
 printf("         |       |       \n"); 
 printf("     %c   |   %c   |   %c     \n", kotak[4], kotak[5], kotak[6]);
 printf("         |       |       \n"); 
 printf("  =======|=======|=======\n");
 printf("         |       |       \n");
 printf("     %c   |   %c   |   %c     \n", kotak[7], kotak[8], kotak[9]);
 printf("         |       |       \n");
 printf("  =======|=======|=======\n");
 printf("\n");
}


/******UNDIAN JIKA MEMENANGKAN PERMAINAN*****/
void undian()
{
  system("@cls||clear");
 int x;
 printf("Selamat, pemain %d menang! Silahkan memiih angka dari 1-10 untuk mendapatkan hadiah!\n", pemenang);
 scanf("%d",&x);

 switch(x)
 {
  case 1:
   printf("Selamat, anda memenangkan sekardus Indomie!\n");
  break; 
  case 4:
   printf("Selamat, anda mendapatkan paket sembako!\n");
  break;
  case 5:
   printf("Selamat, anda mendapatkan voucher JCO!\n");
  break;
  case 7:
   printf("Selamat, anda memenangkan tiket wisata ke Borobudur!\n");
  break;
  case 9:
   printf("Selamat, anda mendapatkan saldo OVO sebesar Rp 50.000!\n");
  break;
  default:
   printf("Maaf anda belum beruntung, silakan coba di lain waktu :) \n");
 }
  getchar();
 printf("~ Terima kasih sudah bermain TIC-TAC-TOE NUSANTARA by jokemijean!\n");
 }


void printArt(FILE *fp)
{
    char read[1000];
    while(fgets(read,sizeof(read),fp) != 0)
    {
        printf("%s",read);
    }        
} 


void delay()
{
    for(int i=0; i<2e8; i++)
    {
        ;
    }
}
//~ Apakah anda ingin bermain lagi ? (Y/N)\n
//int mainlagi;
//char yesno;
//scanf("%c",&yesno);
//if(){
//	
//}else{
//	getchar();
//	printf("~ Terima kasih sudah bermain TIC-TAC-TOE NUSANTARA by jokemijean!\n Press enter to exit program!\n")
//}



