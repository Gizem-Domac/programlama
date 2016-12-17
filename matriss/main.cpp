/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                    KARADENÝZ TEKNÝK ÜNÝVERSÝTESÝ
                                                        BÝLGÝSAYAR MÜHENDÝSLÝÐÝ                                             
                                                               GÝZEM DOMAÇ
                              				  KONU : Complex Sayýlarý Ýçeren Matrislerde Temel Ýþlemler
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
using namespace std;

class Complex{ //complex sayýlar için sýnýf olusturuldu
	public:
    int reel;
    int imajiner;
};

class matrix //matrix sýnýfý oluþturuldu
{
	private:
	
		Complex **karmasik_matris;
		int satir;
		int sutun;

	public:
		matrix(int,int); //matrix adýnda costructor olusturuldu
		void matris_carpim(matrix,matrix); // matrix carpimlarý icin fonksiyon yazýldý
		bool matris_carpim_mumkunmu(matrix); // mumkun olup olmadýgý test edildi
		void matris_toplam(matrix,matrix); // matris toplamlari icin fonksiyon yazýldý
		bool matris_toplam_mumkunmu(matrix); //toplamýn mümkün olup olmadýgý test edildi
		void skaler_carpim(int,matrix); // skaler carpim icin fonksiyon yazýldý
		void matris_atama(matrix); //matris atama icin fonksiyon yazýldý
		
		int get_satir(); 
		int get_sutun(); 
		void set_value(); 
		void ekrana_yaz(); 
		
		
	
};

matrix::matrix(int yeni_satir,int yeni_sutun){
    satir=yeni_satir;
    sutun=yeni_sutun;
    //dinamik matris olusturuldu
    karmasik_matris = new Complex*[satir];

    for (int i = 0; i < satir ;i++)
    {
        karmasik_matris[i] = new Complex[sutun];
    }
    
     for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j <sutun; j++)
        {
            
            karmasik_matris[i][j].reel =0;
            karmasik_matris[i][j].imajiner= 0;
         
        }
    
    }
    
}

void matrix::set_value(){
	// Dinamik matrisin içeriðine deðerler atandý.
	 for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j <sutun; j++)
        {
            cout<<"Matrisin "<<i<<".ninci satir " << j<<".nin sutunun reel degerini giriniz"<<endl;
            cin>>karmasik_matris[i][j].reel;
             cout<<"Matrisin "<<i<<".ninci satir " << j<<".nin sutunun imajinel degerini giriniz"<<endl;
            cin>>karmasik_matris[i][j].imajiner;
            cout<<karmasik_matris[i][j].reel <<"+"<<"(" << karmasik_matris[i][j].imajiner<<"i" <<") - ";
         
        }
        cout<<endl;
    }

	
	
}

int matrix::get_satir(){
return satir;
}

int matrix::get_sutun(){
	return sutun;
}

bool matrix::matris_carpim_mumkunmu(matrix ikinci_matris){
	//matrisin carpimi mümkün olma durumu sadece birinci matrisin sütunu ile ikinci matrisin satýrýnýn esit olmasýna bakýldý
	if(sutun==ikinci_matris.get_satir()){
		return true;
	}
	else{
		return false;
	}
}

void matrix::matris_carpim( matrix ikinci_matris,matrix yeni_matris){
	
	bool kontrol = matris_carpim_mumkunmu(ikinci_matris);
	
	 
	 if(kontrol)
	 {
	 	cout<<"Bu matrisler Carpilabilir!"<<endl;
	 	cout<<"----------------------------------------------------------------"<<endl;
	       
    for (int i = 0; i < satir ; i++)      
	{       	         
    	for (int j = 0; j < ikinci_matris.sutun; j++) 
		{       		  
    		for (int k = 0; k < sutun; k++)    {
    			yeni_matris.karmasik_matris[i][j].reel +=((karmasik_matris[i][k].reel)*(ikinci_matris.karmasik_matris[k][j].reel))-((karmasik_matris[i][k].imajiner)*(ikinci_matris.karmasik_matris[k][j].imajiner));    		
    			yeni_matris.karmasik_matris[i][j].imajiner +=((karmasik_matris[i][k].reel)*(ikinci_matris.karmasik_matris[k][j].imajiner))+((karmasik_matris[i][k].imajiner)*(ikinci_matris.karmasik_matris[k][j].reel));
    		}        

              
   		}
        
    }
    cout<<"YENI_MATRIS"<<endl;
	 yeni_matris.ekrana_yaz();	
}
	 else
	 {
	 	cout<<"Matrislerin Carpimi Mumkun Degildir !"<<endl;
	 	cout<<"----------------------------------------------------------------"<<endl;
	 }



}

bool matrix::matris_toplam_mumkunmu(matrix ikinci_matris){
	//matris toplamý mümkün olmasý için birinci matrisin satýr ve sütunuyla ikinci matrisin satýr ve sütun sayisinin eþit olmasýna bakýldý.
   if((satir==ikinci_matris.get_satir() )&&( sutun==ikinci_matris.get_sutun() ) ){
   	return true;
   }	
   
   else{
   	return false;
   }
		
}

void matrix::matris_toplam(matrix ikinci_matris, matrix yeni_matris){
	bool kontrol = matris_toplam_mumkunmu(ikinci_matris);
	if(kontrol){
	
	for(int i=0;i<satir;i++){
		for(int j=0;j<sutun;j++){
			
			yeni_matris.karmasik_matris[i][j].reel = karmasik_matris[i][j].reel +ikinci_matris.karmasik_matris[i][j].reel;
			yeni_matris.karmasik_matris[i][j].imajiner = karmasik_matris[i][j].imajiner +ikinci_matris.karmasik_matris[i][j].imajiner;
			
		}
	}
	yeni_matris.ekrana_yaz();
    }
   else{
	
	cout<<"Bu matrislerin toplami mumkun degil";
	
   }
	
}

void matrix::skaler_carpim(int deger, matrix yeni_matris){
	for(int i=0;i<satir;i++){
		for(int j=0;j<sutun;j++){
			yeni_matris.karmasik_matris[i][j].reel = (karmasik_matris[i][j].reel) * deger;
			yeni_matris.karmasik_matris[i][j].imajiner = (karmasik_matris[i][j].imajiner) * deger;	
		}
	}
	
	yeni_matris.ekrana_yaz();
	
}

void matrix::matris_atama(matrix yeni){
	for(int i=0;i<satir;i++){
		for(int j=0;j<sutun;j++){
			
			yeni.karmasik_matris[i][j].reel = karmasik_matris[i][j].reel ;
			yeni.karmasik_matris[i][j].imajiner = karmasik_matris[i][j].imajiner ;
			
		}
	}
	yeni.ekrana_yaz();
	
	
}
void matrix::ekrana_yaz(){
	
   for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j <sutun; j++)
        {
            
            cout<<karmasik_matris[i][j].reel <<"+"<<"("<< karmasik_matris[i][j].imajiner<<"i" <<") - ";
         
        }
        cout<<endl;
    }
	
}

int main(int argc, char** argv) { 
//carpim için gerekli olan satýr ve sütun deðerleri setlendi.
	int carpim_ilk_matrisin_satir_degeri; 
	int carpim_ilk_matrisin_sutun_degeri;
	int carpim_ikinci_matrisin_satir_degeri;
	int carpim_ikinci_matrisin_sutun_degeri;
//toplam için gerekli olan satýr ve sütun deðerleri setlendi.
	int toplam_ilk_matrisin_satir_degeri;
	int toplam_ilk_matrisin_sutun_degeri;
	int toplam_ikinci_matrisin_satir_degeri;
	int toplam_ikinci_matrisin_sutun_degeri;
//skaler carpim için gerekli olan satýr ve sütun deðerleri setlendi.	
	int skaler_ilk_matrisin_satir_degeri;
	int skaler_ilk_matrisin_sutun_degeri;
	int skaler;
//atama için gerekli olan satýr ve sütun deðerleri setlendi.	
	int atama_yapilacak_ilk_matrisin_satir_degeri;
	int atama_yapilacak_ilk_matrisin_sutun_degeri;
	
	cout<<"---------------------------------------------------------------------------"<<endl;    
	cout<<"			IKI MATRISIN CARPIMI"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
//kullanýcýdan alýnan deðerler girildi.	
	cout<<"Carpilacak olan ilk matrisin satir degerini giriniz:  ";
	cin>>carpim_ilk_matrisin_satir_degeri;
	cout<<endl<<"Carpilacak olan ilk matrisin sutun degerini giriniz:  ";
	cin>>carpim_ilk_matrisin_sutun_degeri;
	cout<<endl;
	cout<<"Carpilacak olan ikinci matrisin satir degerini giriniz:  ";
	cin>>carpim_ikinci_matrisin_satir_degeri;
	cout<<endl<<"Carpilacak olan ikinci matrisin sutun degerini giriniz:  ";
	cin>>carpim_ikinci_matrisin_sutun_degeri;
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<" BIRINCI MATRISIN DEGERLERINI GIRINIZ"<<endl;
	
	matrix carpim_ilk_matris(carpim_ilk_matrisin_satir_degeri,carpim_ilk_matrisin_sutun_degeri);
	carpim_ilk_matris.set_value();
	
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<" IKINCI MATRISIN DEGERLERINI GIRINIZ"<<endl;
	
	matrix carpim_ikinci_matris(carpim_ikinci_matrisin_satir_degeri,carpim_ikinci_matrisin_sutun_degeri);
	carpim_ikinci_matris.set_value();
	matrix yeni_matris(carpim_ilk_matris.get_satir(),carpim_ikinci_matris.get_sutun());
	
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"BIRINCI MATRIS"<<endl;
	carpim_ilk_matris.ekrana_yaz();
	
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"IKINCI MATRIS"<<endl;
	carpim_ikinci_matris.ekrana_yaz();
	
	
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"IKI MATRISIN CARPIMI"<<endl;
    carpim_ilk_matris.matris_carpim(carpim_ikinci_matris,yeni_matris);
    
    
    cout<<"---------------------------------------------------------------------------"<<endl;    
	    cout<<"			IKI MATRISIN TOPLAMI"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
   //kullanýcýdan alinan deðerler girildi.
    cout<<"Toplanacak olan ilk matrisin satir degerini giriniz:  ";
	cin>>toplam_ilk_matrisin_satir_degeri;
	cout<<endl<<"Toplanacak olan ilk matrisin sutun degerini giriniz:  ";
	cin>>toplam_ilk_matrisin_sutun_degeri;
	cout<<endl;
	cout<<"Toplancak olan ikinci matrisin satir degerini giriniz:  ";
	cin>>toplam_ikinci_matrisin_satir_degeri;
	cout<<endl<<"Toplanacak olan ikinci matrisin sutun degerini giriniz:  ";
	cin>>toplam_ikinci_matrisin_sutun_degeri;
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<" BIRINCI MATRISIN DEGERLERINI GIRINIZ"<<endl;
	
	matrix toplam_ilk_matris(toplam_ilk_matrisin_satir_degeri,toplam_ilk_matrisin_sutun_degeri);
	toplam_ilk_matris.set_value();
	
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<" IKINCI MATRISIN DEGERLERINI GIRINIZ"<<endl;
	
	matrix toplam_ikinci_matris(toplam_ikinci_matrisin_satir_degeri,toplam_ikinci_matrisin_sutun_degeri);
	toplam_ikinci_matris.set_value();
	matrix yeni_matris_toplam(toplam_ilk_matris.get_satir(),toplam_ikinci_matris.get_sutun());
	
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"BIRINCI MATRIS"<<endl;
	toplam_ilk_matris.ekrana_yaz();
	
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"IKINCI MATRIS"<<endl;
	toplam_ikinci_matris.ekrana_yaz();
	
	
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"IKI MATRISIN TOPLAMI"<<endl;
    toplam_ilk_matris.matris_toplam(toplam_ikinci_matris,yeni_matris_toplam);
    
    
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"			BIR MATRISIN SKALER ILE CARPIMI"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	//kullanýcýdan alýnan deðerler girildi.
	cout<<"Skaler ile carpilacak olan ilk matrisin satir degerini giriniz:  ";
	cin>>skaler_ilk_matrisin_satir_degeri;
	cout<<endl<<"Skaler ile carpilacak olan ilk matrisin sutun degerini giriniz:  ";
	cin>>skaler_ilk_matrisin_sutun_degeri;
	cout<<endl;
	matrix skaler_ilk_matris(skaler_ilk_matrisin_satir_degeri,skaler_ilk_matrisin_sutun_degeri);
	
	skaler_ilk_matris.set_value();
	
	matrix yeni_matris_skaler(skaler_ilk_matrisin_satir_degeri,skaler_ilk_matrisin_sutun_degeri);
	
	cout<<"Carpilacak olan skaler degeri giriniz!";
	cin>>skaler;
	
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"MATRISIN SKALER ILE CARPIM SONUCU"<<endl;
	
	skaler_ilk_matris.skaler_carpim(skaler,yeni_matris_skaler);
	
	cout<<"---------------------------------------------------------------------------"<<endl;    
    cout<<"			MATRISIN BASKA MATRISE ATANMASI"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	
	//kullanýcýdan alýnan deðerler girildi.
	cout<<"Atama Yapilacak olan ilk matrisin satir degerini giriniz:  ";
	cin>>atama_yapilacak_ilk_matrisin_satir_degeri;
	cout<<endl<<"Atama Yapilacak olan ilk matrisin sutun degerini giriniz:  ";
	cin>>atama_yapilacak_ilk_matrisin_sutun_degeri;
	cout<<endl;
	
 	matrix atama_yapilacak_ilk_matris(atama_yapilacak_ilk_matrisin_satir_degeri,atama_yapilacak_ilk_matrisin_sutun_degeri);
 	atama_yapilacak_ilk_matris.set_value();
 	
 	matrix yeni_matris_atama(atama_yapilacak_ilk_matrisin_satir_degeri,atama_yapilacak_ilk_matrisin_sutun_degeri);
 	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"BIR MATRISIN ATAMASI"<<endl;
 	atama_yapilacak_ilk_matris.matris_atama(yeni_matris_atama);
	
   
	
	
	return 0;
}
