/**********************************************************************
**                      SAKARYA ÜNİVERSİTESİ
**              BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                 BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                  PROGRAMLAMAYA GİRİŞ DERSİ
**
**                PROJE NUMARASI    : 1
**                ÖĞRENCİ ADI      : ASLIHAN AKBULUT
**                ÖĞRENCİ NUMARASI : G201210080
**                DERS GRUBU       : A (İ.Ö.)
***********************************************************************/

using namespace std;
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

//okuyucu.txt için
string TCNO;
string ad;
string soyad;
string uyeno;
string telno;
string dogumtarih;
string gorev;
int maxkitapsayi = 10;

//kitaplar.txt için 
string ISBN;
string isim;
string yazarad;
string yazarsoyad;
string konu;
string tur;
string sayfasayi;

// odunctxt için 
string OduncTarihi;
string DonusTarihi;
string _OduncTarihi;
string _DonusTarihi;
string sorgu_TC;
string sorgu_ISBN;

//kullanıcı.txt için
string kullaniciad;
string sifre;

string baslamasaat;
string bitissaat;

string _baslamasaat;
string _bitissaat;

string sorgukullanici;
string sorgusifre;

int main()
{
    setlocale(LC_ALL, "Turkish");

    int secim;
    ifstream Dosyaokur; //okunacak dosya tanımlandı.

    Dosyaokur.open("kullanicilar.txt", ios::app); // tanımlanan dosya açıldı.
    cout << "                     Kullanıcı Adınızı Giriniz : "; cin >> sorgukullanici;
    cout << "                        Şifrenizi Giriniz : "; cin >> sorgusifre;
    cout << "                  Programa Giriş Saatinizi Giriniz: "; cin >> _baslamasaat;
    //gerekli değerler istendi.
    int sayac1 = 0;
    int sayac2 = 0;
    while (!(Dosyaokur.eof())) //dosya sonuna kadar okundu sayaclara değer atandı.
    {
        Dosyaokur >> kullaniciad >> sifre >> baslamasaat >> bitissaat;
        if (sorgukullanici == kullaniciad)
        {
            sayac1 = 1;
            if (sorgusifre == sifre)
            {
                sayac2 = 1;
            }
        }

        if (sayac1 == 1)
            break;

    }
    Dosyaokur.close(); //dosya kapatıldı.
    //kullanıcı adının ve şifrenin doğruluğu kontrol edildi.
    if (sayac1 == 0)
    {
        cout << "       !!!Böyle Bir Kullanıcı Bulunamadı!!!" << endl;
        return 0;
    }
    if (sayac1 == 1 && sayac2 == 0)
    {
        cout << "        !!!Şifre Yanlış, Yeniden Deneyiniz!!!" << endl;
        return 0;
    }


menu: //işlemlerin gösterildiği menü oluşturuldu.
    system("cls");
    cout << "  ****************" << " Hoş Geldiniz " << "*****************" << endl;
    cout << "  *" << "  Ne Yapmak İstersiniz?                      *" << endl;
    cout << "  *" << "  1)Okuyucu Kaydı                            *" << endl;
    cout << "  *" << "  2)Okuyucu Kaydı Güncelleme                 *" << endl;
    cout << "  *" << "  3)Okuyucu Silme                            *" << endl;
    cout << "  *" << "  4)Okuyucu Üstündeki Kitapları Görüntüleme  *" << endl;
    cout << "  *" << "  5)Okuyucu Kitap Ödünç Alma                 *" << endl;
    cout << "  *" << "  6)Okuyucu Kitap İadesi                     *" << endl;
    cout << "  *" << "  7)Kitap Ekleme                             *" << endl;
    cout << "  *" << "  8)Kitap Silme                              *" << endl;
    cout << "  *" << "  9)Kitap Düzeltme                           *" << endl;
    cout << "  *" << "  10)Programdan Çık                          *" << endl;
    cout << "  ";
    for (int i = 0; i < 47; i++) //menünü altına 47 yıldız yazdıran döngü.
        cout << "*";
    cout << endl;
    cin >> secim; //secim değeri istendi.

    if (secim == 1)
    {
        system("cls"); //ekran temizlendi.
        char cevap;
        cout << "*********** 1-Okuyucu Kayıt Etme ***********" << endl;
        ofstream DosyaYaz;
        DosyaYaz.open("okuyucu.txt", ios::app);
        //cevap e olduğu sürece dönen ve okuyucuyu dosyaya kaydeden döngü oluşturuldu.
        do
        {
            cout << "********************************************";
            cout << endl << " Okuyucu TC : "; cin >> TCNO;
            cout << endl << " Okuyucu Adı : "; cin >> ad;
            cout << endl << " Okuyucu Soyadı : "; cin >> soyad;
            cout << endl << " Okuyucu Üye No : "; cin >> uyeno;
            cout << endl << " Okuyucu Telefon Numarası : "; cin >> telno;
            cout << endl << " Okuyucu Doğum Tarihi : "; cin >> dogumtarih;
            cout << endl << " Okuyucu Görevi : "; cin >> gorev;
            cout << endl << endl << "     Başka Kayıt Yapacak Mısınız? (e/h) "; cin >> cevap;

            DosyaYaz << "\n" << TCNO << "\n" << ad << "\n" << soyad << "\n" << uyeno << "\n" << telno << "\n" << dogumtarih << "\n" << gorev << "\n" << maxkitapsayi;
        } while (!(cevap == 'h'));


        DosyaYaz.close();
        cout << "************** Okuyucu Kaydı Tamamlandı **************" << endl << endl;
        //bu bölüm her bölüm sonunda var. Menüye dönüşü sağlıyor.
        char sec;
        cout << "     Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
    }
    if (secim == 2)
    {
        system("cls");
        cout << "*********** 2-Okuyucu Kayıt Güncelleme ***********" << endl;

        ifstream DosyaOku("okuyucu.txt");
        ofstream DosyaYaz("gecici.tmp"); //gecici bir dosya oluşturuldu.

        cout << endl << "Güncellenecek Okuyucunun TC. Kimlik Numarasi...:"; cin >> sorgu_TC;

        int sayac = 0;

        while (!(DosyaOku.eof()))//dosya sonuna kadar okunuyor.
        {
            DosyaOku >> TCNO >> ad >> soyad >> uyeno >> telno >> dogumtarih >> gorev >> maxkitapsayi;

            if (sorgu_TC == TCNO) //istenen tc numarasına göre okuyucu yazdırılıyor ve yeni değerler isteniyor.
            {
                cout << endl << "========== Okuyucu Bilgileri ==========" << endl << endl;

                cout << " TC :" << TCNO << endl;
                cout << " Adı :" << ad << endl;
                cout << " Soyadı :" << soyad << endl;
                cout << " Üye Numarası :" << uyeno << endl;
                cout << " Telefon Numarası :" << telno << endl;
                cout << " Doğum Tarihi :" << dogumtarih << endl;
                cout << " Görevi :" << gorev << endl << endl;
                cout << "====================================" << endl;
                cout << " Bilgilerini Güncelleyiniz..." << endl;
                cout << "====================================" << endl;
                cout << " Okuyucu Adı Giriniz :"; cin >> ad;
                cout << " Okuyucu Soyadı Giriniz. :"; cin >> soyad;
                cout << " Okuyucu Üye Numarası :"; cin >> uyeno;
                cout << " Okuyucu Telefon Numarası :"; cin >> telno;
                cout << " Okuyucu Doğum Tarihini Giriniz :"; cin >> dogumtarih;
                cout << " Okuyucu Görevi :"; cin >> gorev;
                //yeni değerler gecici dosyaya yazılır.
                DosyaYaz << "\n" << sorgu_TC << "\n" << ad << "\n" << soyad << "\n" << uyeno << "\n" << telno << "\n" << dogumtarih << "\n" << gorev << "\n" << maxkitapsayi;
                sayac = 1;
                cout << endl << "*********** Güncelleme Başarılı **********";

            }
            if (sorgu_TC != TCNO)
            {
                //diğer okuyucular da gecici dosyaya yazdırlır. 
                DosyaYaz << "\n" << TCNO << "\n" << ad << "\n" << soyad << "\n" << uyeno << "\n" << telno << "\n" << dogumtarih << "\n" << gorev << "\n" << maxkitapsayi;
            }
        }
        if (sayac == 0) //hiç okuyucu yazdırılmazsa bu yazdırılır.
            cout << "!!!!!! Böyle Bir Kayıt Bulunamamıştır !!!!!!" << endl;

        DosyaYaz.close(); //dosyalar kapandı.
        DosyaOku.close();
        remove("okuyucu.txt"); //okuyucu dosya silindi.
        rename("gecici.tmp", "okuyucu.txt"); //geciciye yazılan değerler okuyucuya atandı.
        remove("gecici.tmp");
        char sec;
        cout << endl << "    Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
    }
    if (secim == 3)
    {
        string siloku_TC;
        system("cls");
        ifstream DosyaOku("okuyucu.txt");
        ofstream DosyaYaz("gecici.tmp");
        ifstream DosyaOKU("odunc.txt", ios::app);
        cout << "********* 3- Okuyucu Kaydı Silme ********* " << endl;
        cout << " Silinecek Okuyucu TC Numarasını Giriniz :"; cin >> siloku_TC;
        int sayac3 = 0;
        while (!(DosyaOKU.eof())) //okuyucunu ödünç aldığı bir kitap var mı diye sorgulanır.
        {

            DosyaOKU >> ISBN >> TCNO >> OduncTarihi >> DonusTarihi;
            if (siloku_TC == TCNO)
            {

                sayac3 = 1;
            }

        }
        if (sayac3 == 1) //varsa bu bölüm yazdırılır.
        {
            cout << " Bu Okuyucuyu Silebilmek İçin Önce Bütün Kitapları İade Etmeli! " << endl << endl;
            DosyaYaz.close();
            DosyaOku.close();
            DosyaOKU.close();
            char sec;
            cout << "           Menüye Dönmek İster Misiniz? (e/h) "; cin >> sec;
            if (sec == 'e')
                goto menu;
            if (sec == 'h')
                goto cikis;
            else
                cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
        }

        int sayac = 0;

        //yoksa devam edilir.

        while (!(DosyaOku.eof())) //dosya sonuna kadar okunur bu sırada istenilen okuyucu ekrana yazılır ama gecicidosyaya yazılmaz. 
        {

            DosyaOku >> TCNO >> ad >> soyad >> uyeno >> telno >> dogumtarih >> gorev >> maxkitapsayi;

            if (TCNO == siloku_TC)
            {
                cout << "========== Okuyucu Bilgileri ==========" << endl << endl;

                cout << "TC :" << TCNO << endl;
                cout << "Adı :" << ad << endl;
                cout << "Soyadı :" << soyad << endl;
                cout << "Üye Numarası :" << uyeno << endl;
                cout << "Telefon Numarası :" << telno << endl;
                cout << "Doğum Tarihi :" << dogumtarih << endl;
                cout << "Görevi :" << gorev << endl;
                cout << "========================================" << endl << endl;
                cout << "*********** Başarıyla Silindi **********" << endl;
                sayac = 1;
                continue;
            }
            else //istenilen okuyucu dışındakiler gecici dosyaya yazılır.
                DosyaYaz << "\n" << TCNO << "\n" << ad << "\n" << soyad << "\n" << uyeno << "\n" << telno << "\n" << dogumtarih << "\n" << gorev << "\n" << maxkitapsayi;
        }

        if (sayac == 0) // hiç okuyucu yazdırılmazsa bu bölüm yazdırılır.
        {
            cout << endl;
            cout << "!!!!! Böyle bir okuyucu bulunamadı !!!!! " << endl;
        }
        DosyaYaz.close();
        DosyaOku.close();
        DosyaOKU.close();
        remove("okuyucu.txt");
        rename("gecici.tmp", "okuyucu.txt"); //okuyucu dosyası silinir gecici okuyucuya aktarılır
        remove("gecici.tmp");
        char sec;
        cout << "   Menüye Dönmek İster Misiniz? (e/h) "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;

    }
    if (secim == 4)
    {
        system("cls");
        string liste_TC;
        cout << "========= 4-Kitap Listeleme ==========" << endl;

        ifstream DosyaOku("okuyucu.txt");
        ifstream DosyaOKU("odunc.txt");

        cout << "Kitapları Listelenecek Okuyucunun TC. Kimlik Numarası..:"; cin >> liste_TC;
        int sayac = 0;
        while (!(DosyaOku.eof())) //istenilen okuyucu ekrana yazdırılır.
        {
            DosyaOku >> TCNO >> ad >> soyad >> uyeno >> telno >> dogumtarih >> gorev >> maxkitapsayi;
            if (liste_TC == TCNO)
            {
                cout << "========== Okuyucu Bilgileri ==========" << endl;
                cout << " TC :" << TCNO << endl;
                cout << " Adı :" << ad << endl;
                cout << " Soyadı :" << soyad << endl;
                cout << " Üye Numarası :" << uyeno << endl << endl;
                cout << " Telefon Numarası :" << telno << endl;
                cout << " Doğum Tarihi :" << dogumtarih << endl;
                cout << " Görevi :" << gorev << endl;
                cout << "========================================" << endl << endl;
                sayac = 1;

            }
            if (sayac == 1)
                break;
        }
        if (sayac == 0) //ekrana yazdırma olmazsa bu bölüm yazdırılır.
        {
            cout << "!!!!!!!!! Böyle Bir Okuyucu Bulunamamıştır !!!!!!!!!" << endl;
            DosyaOKU.close();
            DosyaOku.close();


            char sec;
            cout << "        Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
            if (sec == 'e')
                goto menu;
            if (sec == 'h')
                goto cikis;
            else
                cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
        }
        int sayac1 = 0;
        string isbn;

        ifstream DosyaOKUR("odunc.txt");
        while (!(DosyaOKUR.eof()))
        {
            ifstream Dosyaoku("kitaplar.txt",ios::app);


            DosyaOKUR >> isbn >> TCNO >> OduncTarihi >> DonusTarihi; //ödunç dosyası okunur. İstenilen okuyucu sorgulanır.

            if (liste_TC == TCNO)
            {
                cout << "Ödünç Alınan Kitap ISBN: " << isbn;
                while (!(Dosyaoku.eof())) //kitaplar dosyası okunur. istenilen kitaplar yazdırılır.
                {

                    Dosyaoku >> ISBN >> isim >> yazarad >> yazarsoyad >> konu >> tur >> sayfasayi;
                    if (isbn == ISBN)
                    {
                        cout << endl << "***************************************" << endl;

                        cout << " Kitap Adı : " << isim << endl;
                        cout << " Yazar Adı : " << yazarad << endl;
                        cout << " Yazar Soyadı : " << yazarsoyad << endl;
                        cout << " Kitabın Konusu : " << konu << endl;
                        cout << " Kitabın Türü : " << tur << endl;
                        cout << " Kitabın Sayfa Sayısı : " << sayfasayi << endl << endl;
                        cout << "***************************************" << endl;
                        sayac1 = 1; //ödünç alınan kitap varsa sayac 1 olur.
                    }

                }

                

            }
            Dosyaoku.close();
        }

        if (sayac1 == 0) // sayac 1 olmadıysa bu bölüm yazdırılır.
            cout << endl << "!!! Ödünç Almış Olduğunuz Bir Kitap Kaydı Bulunamadı !!!" << endl;
        DosyaOKUR.close();
        DosyaOKU.close();
        DosyaOku.close();


        char sec;
        cout << "        Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
    }
    if (secim == 5)
    {
        system("cls");
        char secim2;

        cout << "========= 5-Kitap Ödünç Alma ==========" << endl << endl;
        ifstream DosyaOku("okuyucu.txt");
        ifstream DosyaOKU("odunc.txt", ios::app);
        ofstream DosyaYaz("gecici.tmp");

        cout << "Kitap Ödünç Alacak Okuyucunun TC. Kimlik Numarası :"; cin >> sorgu_TC;
        int sayac = 0;
        while (!(DosyaOKU.eof())) //kaç kitap ödünç alınmış onu sorguluyoruz. ve sayac değeri bu değer oluyor.
        {

            DosyaOKU >> ISBN >> TCNO >> OduncTarihi >> DonusTarihi;
            if (sorgu_TC == TCNO)
            {

                sayac++;
            }

        }
        DosyaOKU.close();
        if (sayac == maxkitapsayi) //ödünç alınan kitap sayısı maximum kitap sayısındaysa daha fazla kitap ödünç aldırmıyoruz.
        {
            cout << "!! Maksimum Kitap Sayısında Olduğunuzdan Kitap Ödünç Alamazsınız !!" << endl << endl;
            DosyaYaz.close();
            DosyaOku.close();


            char sec;
            cout << "        Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
            if (sec == 'e')
                goto menu;
            if (sec == 'h')
                goto cikis;
            else
                cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
        }
        int sayac2 = 0;
        while (!(DosyaOku.eof())) //istenilen okuyucu ekrana yazdırılır.
        {
            DosyaOku >> TCNO >> ad >> soyad >> uyeno >> telno >> dogumtarih >> gorev >> maxkitapsayi;
            if (sorgu_TC == TCNO)
            {
                cout << "========== Okuyucu Bilgileri ==========" << endl;
                cout << " TC :" << TCNO << endl;
                cout << " Adı :" << ad << endl;
                cout << " Soyadı :" << soyad << endl;
                cout << " Üye Numarası :" << uyeno << endl ;
                cout << " Telefon Numarası :" << telno << endl;
                cout << " Doğum Tarihi :" << dogumtarih << endl;
                cout << " Görevi :" << gorev << endl;
                cout << "***************************************" << endl;
                cout << endl;

                sayac2 = 1;

            }
            if (sayac2 == 1)
                break;

        }
        if (sayac2 == 0) //yazdırılma olmazsa bu bölüm yazdırılır.
        {
            cout << "!!!!! Böyle Bir Okuyucu Bulunamamıştır !!!!!" << endl;
            DosyaYaz.close();
            DosyaOku.close();


            char sec;
            cout << "        Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
            if (sec == 'e')
                goto menu;
            if (sec == 'h')
                goto cikis;
            else
                cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
        }


        ifstream DosyaOkur("odunc.txt");
        int sayac3 = 0;
        do //cevap e olduğu sürece dönen döngü.
        {

            if (sayac3 == maxkitapsayi - sayac) //ard arda kitap alımında max kitapa ulaştığınızda uyarı verir.
            {
                cout << "!!! Maksimum Kitaba Ulaştınız. Daha Fazla Kitap Ödünç Alamazsınız. !!!" << endl << endl;
                DosyaYaz.close();
                DosyaOku.close();
                DosyaOkur.close();


                char sec;
                cout << "          Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
                if (sec == 'e')
                    goto menu;
                if (sec == 'h')
                    goto cikis;
                else
                    cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
            }
            //ödünç alınacak kitabın bilgisi istenir.
            cout << endl << " Ödünç Almak İstediğiniz Kitabın ISBN'sini Giriniz : "; cin >> sorgu_ISBN;

            cout << endl << " Kitabın Ödünç Alınma Tarihini Giriniz: "; cin >> _OduncTarihi;

            cout << endl << " Kitabın Geri Getirileceği Tarihi Yazınız : "; cin >> _DonusTarihi;

            while (!(DosyaOkur.eof())) //Geçici dosyaya eski değerler yazılır ayrıca istenilen kitap kullanıcıdan alınana bilgilerle dosyaya yazdırılır.
            {
                DosyaOkur >> ISBN >> TCNO >> OduncTarihi >> DonusTarihi;
                if (ISBN != sorgu_ISBN)
                {
                    DosyaYaz << "\n" << ISBN << "\n" << TCNO << "\n" << OduncTarihi << "\n" << DonusTarihi;

                }

            }
            DosyaYaz << "\n" << sorgu_ISBN << "\n" << sorgu_TC << "\n" << _OduncTarihi << "\n" << _DonusTarihi;

            cout << endl << "********* Ödünç Alınma Bilgisi Başarıyla Kaydedilmiştir *********" << endl << endl;
            sayac3++;
            cout << "   Başka Kitap Ödünç Alacak Mısınız ? (e/h) "; cin >> secim2;


        } while (secim2 == 'e');

    atla:
        DosyaYaz.close();
        DosyaOku.close();
        DosyaOkur.close();
        remove("odunc.txt");
        rename("gecici.tmp", "odunc.txt"); //ödünç dosyası silinir.Geçici dosyasındakiler ödünç dosyasına aktarılır.
        remove("gecici.tmp");

        char sec;
        cout << endl << "      Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
    }
    if (secim == 6)
    {
        system("cls");
        cout << "******6 - Kitap İadesi * ********" << endl;
        int sayac = 0;
        string iade_TC;
        cout << "Kitap İade Edecek Okuyucunun TC Numarasını Giriniz :"; cin >> iade_TC;

        ifstream DosyaOku("okuyucu.txt");

        while (!(DosyaOku.eof())) //istenilen okuyucu ekrana yazdırılır.
        {
            DosyaOku >> TCNO >> ad >> soyad >> uyeno >> telno >> dogumtarih >> gorev >> maxkitapsayi;

            if (TCNO == iade_TC)
            {

                cout << "========== Okuyucu Bilgileri ==========" << endl;
                cout << " TC :" << iade_TC << endl;
                cout << " Adı :" << ad << endl;
                cout << " Soyadı :" << soyad << endl;
                cout << " Üye Numarası :" << uyeno << endl;
                cout << " Telefon Numarası :" << telno << endl;
                cout << " Doğum Tarihi :" << dogumtarih << endl;
                cout << " Okuyucu Görevi :" << gorev << endl;
                cout << "========================================" << endl << endl;
                sayac = 1;
            }

        }
        DosyaOku.close();
        if (sayac == 0) //yazdırılma olmazsa bu bölüm yazdırılır.
        {
            cout << "!!!!! Böyle Bir Okuyucu Bulunamamıştır !!!!!" << endl;

            char sec;
            cout << "        Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
            if (sec == 'e')
                goto menu;
            if (sec == 'h')
                goto cikis;
            else
                cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
        }

        int sayac5 = 0;
        string silkitap_ISBN;
        ofstream DosyaYaz("gecici.tmp");
        ifstream Dosyaoku("odunc.txt");
        cout << " İade Edilecek Kitabın ISBN'sini Giriniz : "; cin >> silkitap_ISBN;
        while (!(Dosyaoku.eof())) //ödünç verilen kitap dışınakiler gecici dosyaya yazdırılır.
        {
            Dosyaoku >> ISBN >> TCNO >> OduncTarihi >> DonusTarihi;

            if (ISBN != silkitap_ISBN)
            {
                DosyaYaz << "\n" << ISBN << "\n" << TCNO << "\n" << OduncTarihi << "\n" << DonusTarihi;

            }
            else
                sayac5 = 1;

        }
        if (sayac5 == 0)// yazdırılma olmazsa bu bölüm yazdırılır.
        {
            cout << endl << "  !!! Böyle bir kitap ödünç alınmamıştır !!!" << endl;
            goto atla2; //o ana kadar alınan kitaplar silinmesin diye.
        }

        cout << endl << "************ İade İşleminiz Gerçekleşmiştir *************" << endl << endl;


    atla2:
        DosyaYaz.close();
        Dosyaoku.close();


        remove("odunc.txt");
        rename("gecici.tmp", "odunc.txt");
        remove("gecici.tmp");

        char sec;
        cout << "         Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
    }
    if (secim == 7)
    {
        system("cls");
        char cevap;
        ofstream DosyaYaz("kitaplar.txt");
        cout << "************ 7-Kitap Ekleme ***********" << endl;
        do //cevap e olduğu sürece dönen döngü.
        { //istenilen kitap hem ekrana hem de dosyaya yazdırılır.
            cout << " Eklemek İstediğiniz Kitabın ISBN'sini Giriniz: "; cin >> ISBN;
            cout << " Kitabın İsmini Giriniz: "; cin >> isim;
            cout << " Yazarın Adını Giriniz: "; cin >> yazarad;
            cout << " Yazarın Soyadını Giriniz: "; cin >> yazarsoyad;
            cout << " Kitabın Konusunu Giriniz: "; cin >> konu;
            cout << " Kitabın Türünü Giriniz: "; cin >> tur;
            cout << " Kitabın Sayfa Sayısını Giriniz: "; cin >> sayfasayi;
            cout << "*************************************************" << endl;
            cout << endl << "   Baska kayit yapacak misin?(e/h) "; cin >> cevap;

            DosyaYaz << "\n" << ISBN << "\n" << isim << "\n" << yazarad << "\n" << yazarsoyad << "\n" << konu << "\n" << tur << "\n" << sayfasayi;

        } while (cevap == 'e');


        DosyaYaz.close();
        cout << endl << "************* Dosyaya Kayıt Tamamlandı **************" << endl;
        char sec;
        cout << "      Menüye Dönmek İster Misiniz? (e/h)"; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;

    }
    if (secim == 8)
    {
        system("cls");
        cout << "*********** 8-Kitap Silme *********** " << endl;
        string silkitap_ISBN;
        cout << " Silinecek Kitabın ISBN'sini Giriniz :"; cin >> silkitap_ISBN;

        ifstream DosyaOku("kitaplar.txt");
        ofstream DosyaYaz("gecici.tmp");
        int sayac = 0;

        while (!(DosyaOku.eof()))//istenilen kitap ekrana yazdırılır ama dosyaya yazdırılmaz. onun dışındakiler gecici dosyaya yazılır.
        {

            DosyaOku >> ISBN >> isim >> yazarad >> yazarsoyad >> konu >> tur >> sayfasayi;

            if (ISBN == silkitap_ISBN)
            {
                cout << endl << "========== Kitap Bilgileri ==========" << endl;
                cout << " ISBN :" << silkitap_ISBN << endl;
                cout << " Kitabın Adı :" << isim << endl;
                cout << " Yazarın Adı :" << yazarad << endl;
                cout << " Yazarın Soyadı :" << yazarsoyad << endl;
                cout << " Kitabın Konusu :" << konu << endl;
                cout << " Kitabın Türü :" << tur << endl;
                cout << " Kitabın Sayfa Sayısı :" << sayfasayi << endl;
                cout << "========================================" << endl << endl;
                cout << "     Silme Isleminiz Gerceklesmistir " << endl << endl;
                sayac = 1;

            }
            else
                DosyaYaz << "\n" << ISBN << "\n" << isim << "\n" << yazarad << "\n" << yazarsoyad << "\n" << konu << "\n" << tur << "\n" << sayfasayi;

        }
        if (sayac == 0)//ekrana yazılma olmazsa bu bölüm yazdırılır.
        {
            cout << endl << "!!!!!!!! Böyle bir kitap kaydı bulunamadı !!!!!!!!" << endl;

        }
        DosyaYaz.close();
        DosyaOku.close();

        remove("kitaplar.txt");
        rename("gecici.tmp", "kitaplar.txt");//kitaplar dosyası temizlenir. gecic dosyasındakiler kitaplara aktarılır. 
        remove("gecici.tmp");
        char sec;
        cout << "     Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;
    }
    if (secim == 9)
    {
        system("cls");
        cout << "*********** 9-Kitap Düzeltme ***********" << endl;
        string guncelkitap_ISBN;
        ifstream DosyaOku("kitaplar.txt");
        ofstream DosyaYaz("gecici.tmp");

        cout << " Düzeltilecek Kitabın ISBN'sini Giriniz : "; cin >> guncelkitap_ISBN;

        int sayac = 0;
        while (!(DosyaOku.eof())) //istenilen kitap ekrana yazdırılır ve yeni bilgileri istenir. yeni bilgiler gecici dosyaya yazdırılır.
        {
            DosyaOku >> ISBN >> isim >> yazarad >> yazarsoyad >> konu >> tur >> sayfasayi;

            if (guncelkitap_ISBN == ISBN)
            {
                cout << endl << "========== Kitap Bilgileri ==========" << endl;
                cout << " ISBN :" << guncelkitap_ISBN << endl;
                cout << " Kitabın Adı :" << isim << endl;
                cout << " Yazarın Adı :" << yazarad << endl;
                cout << " Yazarın Soyadı :" << yazarsoyad << endl;
                cout << " Kitabın Konusu :" << konu << endl;
                cout << " Kitabın Türü :" << tur << endl;
                cout << " Kitabın Sayfa Sayısı :" << sayfasayi << endl << endl;
                cout << "========================================" << endl;
                cout << "Kitap Bilgilerini Güncelleyiniz..." << endl;
                cout << "========================================" << endl << endl;
                cout << " Kitabın Adını Giriniz :"; cin >> isim;
                cout << " Yazarın Adını Giriniz. :"; cin >> yazarad;
                cout << " Yazarın Soyadını Giriniz :"; cin >> yazarsoyad;
                cout << " Kitabın Konusunu Giriniz :"; cin >> konu;
                cout << " Kitabın Türünü Giriniz :"; cin >> tur;
                cout << " Kitabın Sayfa Sayısını Giriniz :"; cin >> sayfasayi;

                DosyaYaz << "\n" << ISBN << "\n" << isim << "\n" << yazarad << "\n" << yazarsoyad << "\n" << konu << "\n" << tur << "\n" << sayfasayi;
                sayac = 1;
                cout << "******** Güncelleme Başarılı ********" << endl << endl;
            }
            if (guncelkitap_ISBN != ISBN)//istenilen kitap dışındakiler aynen geciciye yazdırılır.
            {
                DosyaYaz << "\n" << ISBN << "\n" << isim << "\n" << yazarad << "\n" << yazarsoyad << "\n" << konu << "\n" << tur << "\n" << sayfasayi;
            }
        }
        if (sayac == 0) //hiç bir ekrana yazdırma olmazsa bu bölüm yazdırılır.
            cout << "!!!!!!!! Böyle Bir Kitap Bulunamadı !!!!!!!! " << endl;

        DosyaYaz.close();
        DosyaOku.close();
        remove("kitaplar.txt");
        rename("gecici.tmp", "kitaplar.txt");
        remove("gecici.tmp");
        char sec;
        cout << "     Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
        if (sec == 'h')
            goto cikis;
        else
            cout << "  Geçersiz Karakter Yeniden Deneyiniz. " << endl; goto cikis;

    }
    if (secim == 10)
    {
        //cıkışa gidilir.
        goto cikis;
    }
    if (secim > 10 || secim < 1) //geçersiz bir rakam girilirse.
    {
        system("cls");
        cout << "!!! Geçersiz Bir Seçim Yaptınız. Yeniden Deneyiniz !!!" << endl;
        char sec;
        cout << "   Menüye Dönmek İster Misiniz? (e/h)  "; cin >> sec;
        if (sec == 'e')
            goto menu;
    cikis:


        system("cls");
        ofstream DosyaYaz("gecici.tmp");
        ifstream DosyaOkur("kullanicilar.txt");

        cout << endl << " Programdan çıkış saatinizi yazınız : "; cin >> _bitissaat;

        while (!(DosyaOkur.eof())) //programın başında ve sonunda alınan değerler ışığında kullanıcılar dosyasında güncelleme yapılır.
        {
            DosyaOkur >> kullaniciad >> sifre >> baslamasaat >> bitissaat;
            if (kullaniciad != sorgukullanici)
            {
                DosyaYaz << "\n" << kullaniciad << "\n" << sifre << "\n" << baslamasaat << "\n" << bitissaat;
            }

        }

        DosyaYaz << "\n" << sorgukullanici << "\n" << sorgusifre << "\n" << _baslamasaat << "\n" << _bitissaat;

        //giriş yapan kullanıcını giriş ve çıkış saatleri kayıt edilir.

        DosyaYaz.close();
        DosyaOkur.close();
        remove("kullanicilar.txt");//kullanıcılar silinir.
        rename("gecici.tmp", "kullanicilar.txt");//gecici dosyası kullanıcılara aktarılır.
        remove("gecici.tmp");

    }



    return 0;
}