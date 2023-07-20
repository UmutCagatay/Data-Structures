import java.util.Scanner;

public class Test {
	public static void main(String[] args) {
		String text = null;
		System.out.print("Kodu giriniz: ");
		Scanner scan = new Scanner(System.in);
		text = scan.nextLine();
		Oyun o = new Oyun(text);
		o.OyunBaslat();
	}
	
}
