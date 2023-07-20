import java.util.Iterator;
import java.util.Scanner;

public class Oyun {
	private int koloni_sayisi;
	private int alive_koloni;
	private int tur_sayisi;
	Taktik taktik_listesi[];
	IUretim uretim_listesi[];
	Koloni koloni_listesi[];
	
	public Oyun(String text) {
		this.tur_sayisi = 1;
		this.taktik_listesi = new Taktik[2];
		this.taktik_listesi[0] = new ATaktik();
		this.taktik_listesi[1] = new BTaktik();
		this.uretim_listesi = new IUretim[2];
		this.uretim_listesi[0] = new AUretim();
		this.uretim_listesi[1] = new BUretim();
		this.koloni_sayisi = KoloniSayisiBul(text);
		this.alive_koloni = koloni_sayisi;
		this.koloni_listesi = new Koloni[koloni_sayisi];
		
		OyunKolonileriOlustur(text);
		SembolYukle();
	}
	
	public void OyunBaslat()
	{
		Scanner scan = new Scanner(System.in);
		clearScreen();
		do {
			if ((alive_koloni == 0) || (alive_koloni == 1)) {
				break;
			}
			EkranaYazdir();
			SavasYap();
			UretimYap();
			TurAtla();
			
			scan.nextLine();
			
		} while (alive_koloni != 1);
		EkranaYazdir();
		if (alive_koloni == 0) {
			System.out.println("Son kolonilerin populasyonlari veya yemek stoklari bir sonraki tura gecmeye yeterli olmadi. Son koloniler kendi kendilerini yok ettiler.");
		}
		System.out.println("Oyun sona erdi...");
		scan.nextLine();
	}
	private void EkranaYazdir()
	{
		System.out.println("Tur Sayisi: " + tur_sayisi + "\t Hayatta Olan Koloni Sayisi: " + alive_koloni);
		System.out.println("------------------------------------------------------------------");
		System.out.println("Koloni\t Populasyon\t Yemek Stogu\t Kazanma     Kaybetme");
		for (int i = 0; i < koloni_sayisi; i++) {
			System.out.print("   " + (char)koloni_listesi[i].getSembol() + "\t");
			if (koloni_listesi[i].isIs_alive() == true) {
				System.out.format("%9s %15s %10s %13s",koloni_listesi[i].getPopulasyon() , koloni_listesi[i].getYemekStok(), koloni_listesi[i].getKazanma(), koloni_listesi[i].getKaybetme());
				System.out.println();
			}
			else
			{
				System.out.format("%9s %15s %10s %13s","--" , "--", "--", "--");
				System.out.println();
			}
		}
		System.out.println("------------------------------------------------------------------");
		tur_sayisi++;
	}
	private void SavasYap()
	{
		int index = 0;
		for (int i = 0; i < koloni_sayisi; i++) 
		{
			if (koloni_listesi[i].isIs_alive() == true) 
			{
				index = i + 1;
				for (int j = 0; j < koloni_sayisi-(i+1); j++) 
				{
					if (koloni_listesi[index].isIs_alive() == true) 
					{
						Savastir(koloni_listesi[i], koloni_listesi[index]);
						index++;
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				continue;
			}
		}
	}
	private void Savastir(Koloni koloni1, Koloni koloni2)
	{
		int random = (int)(Math.random() * 2);
		int koloni1_savasgucu;
		int koloni2_savasgucu;
		if (random == 0) {
			taktik_listesi[0].TaktikPopulasyonAl(koloni1.getPopulasyon());
			koloni1_savasgucu = taktik_listesi[0].Savas();
		}
		else
		{
			taktik_listesi[1].TaktikPopulasyonAl(koloni1.getPopulasyon());
			koloni1_savasgucu = taktik_listesi[1].Savas();
		}
		random = (int)(Math.random() * 2);
		if (random == 0) {
			taktik_listesi[0].TaktikPopulasyonAl(koloni2.getPopulasyon());
			koloni2_savasgucu = taktik_listesi[0].Savas();
		}
		else
		{
			taktik_listesi[1].TaktikPopulasyonAl(koloni2.getPopulasyon());
			koloni2_savasgucu = taktik_listesi[1].Savas();
		}
		double yuzde = Math.abs(koloni1_savasgucu - koloni2_savasgucu) / 1000.0;
		
		if (koloni1_savasgucu == koloni2_savasgucu) 
		{
			if (koloni1.getPopulasyon() == koloni2.getPopulasyon()) {
				random = (int)(Math.random() * 2);
				if (random == 0) 
				{
					SavasKazanKaybet(koloni1, koloni2, yuzde);
				}
				else
				{
					SavasKazanKaybet(koloni2, koloni1, yuzde);
				}
			}
			else if (koloni1.getPopulasyon() > koloni2.getPopulasyon())
			{
				SavasKazanKaybet(koloni1, koloni2, yuzde);
			}
			else
			{
				SavasKazanKaybet(koloni2, koloni1, yuzde);
			}
		}
		else if(koloni1_savasgucu > koloni2_savasgucu)
		{
			SavasKazanKaybet(koloni1, koloni2, yuzde);
		}
		else
		{
			SavasKazanKaybet(koloni2, koloni1, yuzde);
		}
	}
	private void UretimYap()
	{
		int random;
		int koloni_uretimgucu;
		for (int i = 0; i < koloni_sayisi; i++) 
		{
			if (koloni_listesi[i].isIs_alive() == true) {
				random = (int) (Math.random() * 2);
				
				if (random == 0) {
					uretim_listesi[0].UretimPopulasyonAl(koloni_listesi[i].getPopulasyon());
					koloni_uretimgucu = uretim_listesi[0].Uret();
				}
				else
				{
					uretim_listesi[1].UretimPopulasyonAl(koloni_listesi[i].getPopulasyon());
					koloni_uretimgucu = uretim_listesi[1].Uret();
				}
				koloni_listesi[i].setYemekStok(koloni_listesi[i].getYemekStok() + koloni_uretimgucu);
			}
			else
			{
				continue;
			}
		}
	}
	private void TurAtla()
	{
		for (int i = 0; i < koloni_sayisi; i++) {
			if (koloni_listesi[i].isIs_alive() == true) {
				koloni_listesi[i].KoloniTurAtla();
				if (koloni_listesi[i].getPopulasyon() <= 0 || koloni_listesi[i].getYemekStok() <= 0) {
					koloni_listesi[i].setIs_alive(false);
					alive_koloni--;
				}
			}
			else
			{
				continue;
			}
		}
	}
	private void SavasKazanKaybet(Koloni koloni1, Koloni koloni2, double yuzde)
	{
		if (koloni2.isIs_alive() == false) {
			
		}
		else
		{
			koloni2.setPopulasyon((int)(koloni2.getPopulasyon() - (koloni2.getPopulasyon() * yuzde)));
			int yemek = koloni2.getYemekStok() / 10;
			koloni2.setYemekStok(koloni2.getYemekStok()-yemek);
			koloni1.setYemekStok(koloni1.getYemekStok()+yemek);
			KoloniKazan(koloni1);
			KoloniKaybet(koloni2);
			if ((koloni2.getPopulasyon() <= 0) || (koloni2.getYemekStok() <= 0)) {
				koloni2.setIs_alive(false);
				alive_koloni--;
			}
		}
	}
	
	private void KoloniKazan(Koloni tempKoloni) 
	{
		tempKoloni.setKazanma(tempKoloni.getKazanma()+1);
	}
	private void KoloniKaybet(Koloni tempKoloni) 
	{
		tempKoloni.setKaybetme(tempKoloni.getKaybetme()+1);
	}
	private void OyunKolonileriOlustur(String text)
	{
		String sayi = "";
		int koloni_sayac = 0;
		int len = text.length();
		for (int i = 0; i < len; i++) {
			if (text.charAt(i) == ' ' && sayi != "") {
				int gec = Integer.parseInt(sayi);
				koloni_listesi[koloni_sayac] = new Koloni(gec);
				koloni_sayac++;
				sayi = "";
				continue;
			}
			StringBuilder sb = new StringBuilder();
			sb.append(text.charAt(i));
			sayi += sb.toString();
		}
		if (text.charAt(len-1) != ' ') {
			int gec = Integer.parseInt(sayi);
			koloni_listesi[koloni_sayac] = new Koloni(gec);
		}
	}
	private void SembolYukle()
	{
		for (int i = 0; i < this.koloni_sayisi; i++) 
			this.koloni_listesi[i].setSembol(65 + i);
	}
	private int KoloniSayisiBul(String text)
	{
		int adet = 0;
		int len = text.length();
		
		for (int i = 0; i < len; i++) {
			if (text.charAt(i) == ' ') {
				adet++;
			}
		}
		if (text.charAt(len-1) != ' ') {
			adet++;
		}
		
		return adet;
	}
	public void clearScreen() {  

		   System.out.print("\033[H\033[2J"); 
		   System.out.flush();  

		}
}
