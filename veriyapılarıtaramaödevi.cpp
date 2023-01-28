
#include <iostream>
#include <cstddef>
using namespace std;
class Node {
public:
	int isno;
	int evno;
	int cepno;
	string kullanıcıadı;
	Node* next;
	Node* head = NULL;
};
void tümlisteyazdır(Node* n) { 
	if (n == NULL) {
		cout << "liste bos" << endl;
		cout << "**********************" << endl;
	}
	while (n!= NULL)
	{
		cout << "*********************************" << endl;
		cout << " cep no: "<<n->cepno << endl;
		cout <<"evno :"<< n->evno << endl;
		cout << " is no :"<<n->isno << endl;
		cout <<"kullanici adi:"<<n->kullanıcıadı << endl;
		cout << "*********************************" << endl;
		n = n->next;
	}
	return;
}
void kisisayısı(Node* n) 
{
	int sayac = 0;
	while (n != NULL)
	{
		sayac = sayac + 1;
		n = n->next;
	}
	cout << "********************************************" << endl;
		cout << "kisi sayisi=" << sayac << endl;
		cout << "********************************************" << endl;
	
}
void kişiekle(Node **bas,int cepno,int evno,int isno,string isim) 
{
		Node* sonaekle = new Node();
		sonaekle->cepno = cepno;
		sonaekle->evno = evno;
		sonaekle->isno = isno;
		sonaekle->kullanıcıadı = isim;
		sonaekle->next = NULL;
		if (*bas == NULL) 
		{
			*bas = sonaekle;
			return;
		}
		Node* sonuncu = *bas; 
		while (sonuncu->next != NULL) 
		{
			sonuncu = sonuncu->next;
		}
		sonuncu->next = sonaekle;  
} 

void kişibulma(Node* n, string isim)
{
	int  sayac = 0;
	int sayac2 = 0;
	while (n != NULL)
	{
		sayac = sayac + 1;
		if (n->kullanıcıadı == isim)
		{
			cout << "********************************************" << endl;
			cout << "kisi bulundu" << endl;
			cout << " isim = " << n->kullanıcıadı << endl;
			cout << "cep numarasi = " << n->cepno<< endl;
			cout << "ev numarasi =" << n->evno << endl;
			cout << " is numarasi =" << n->isno << endl;
			cout << "kisi " << sayac << ". sirada bulunmaktadir" << endl;
			cout << "********************************************" << endl;
			sayac2 = sayac2 + 1;
			break;
		}
		else
		{
			n = n->next; 
		}
	}
	if (sayac2 != 1)
	{
		cout << "*********************************" << endl;
		cout << "boyle biri yok" << endl;
		cout << "*********************************" << endl;

	}
}
void numarayagörebulma(Node* n, int cepnumarası)
{
	int sayac2 = 0;
	int sayac = 0;
	while (n != NULL)
	{
		sayac = sayac + 1;
		if (n->cepno == cepnumarası)
		{
			cout << "kisi bulundu" << endl;
			cout << " isim  = " << n->kullanıcıadı << endl;
			cout << "cep numarasi = " << n->cepno << endl;
			cout << "ev numarasi =" << n->evno << endl;
			cout << " is numarasi =" << n->isno << endl;
			cout << "kisi " << sayac << ". sirada bulunmaktadir" << endl;
			sayac2 = sayac2 + 1;
			break;
		}
		else
		{ 
			n = n->next;
		}
	}
	if (sayac2 != 1) {
		cout << "*********************************" << endl;
		cout << "boyle bir numara yok" << endl;
		cout << "*********************************" << endl;
	}
}
int main()
{
	
	Node* head = NULL;
	cout << "Telefon Rehberine Hosgeldiniz !" << endl;
	int secim;
	do {
		cout << "1. Yeni kisi olustur" << endl;
		cout << "2. Kisi sayisini göster" << endl;
		cout << "3. Isme Gore Kisi Arama" << endl;
		cout << "4. Cep Numarasina  Gore Kisi Arama" << endl;
		cout << "5. Hepsini listele" << endl;
		cout << "6. Cikis" << endl;
		cin >> secim;
		switch (secim)
		{
		case 1:
		{
			cout << "Kisinin adini giriniz" << endl;
			string isim;
			cin >> isim;
			cout << "Kisinin is numarasini   giriniz" << endl;
			int isNumara;
			cin >> isNumara;
			cout << "Kisinin ev numarasini giriniz" << endl;
			int evNumarası;
			cin >> evNumarası;
			cout << "Kisinin cep numarasini  giriniz" << endl;
			int cepNumarası;
			cin >> cepNumarası;
			cout << "Kisi  olusturma basarili" << endl;
				kişiekle(&head, evNumarası, cepNumarası, isNumara, isim);
			break; }
		case 2:
		{ kisisayısı(head);
		break;
		}case 3:
		{    
			cout << "bulmak istediginiz ismi giriniz" << endl;
			string isimm;
			cin >> isimm;
			kişibulma(head, isimm);
			break;
		}case 4: {
			cout << "hangi  numaraya gore bulmak istiyorsunuz ?" << endl;
			int numara;
			cin >> numara;
			numarayagörebulma(head, numara);
			break;
		}
		case 5: {
			cout << "********************************************" << endl;
			cout << "liste yazdiriliyor" << endl;
			cout << endl;
			tümlisteyazdır(head);
			break;
		} case 6: {
			cout << "cikis yapiliyor" << endl;
			break;
		}
		default: 
			cout << "yanlis sayi girdiniz" << endl; 
			break;
		}
	} while (secim<6);

}

