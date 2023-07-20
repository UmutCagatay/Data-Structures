/**
*
* @author Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
* @since 15.04.2023
* <p>
* Dosyada okunan siniflarin atandigi sinif. Ayni zamanda kendi icerisinde dosyadan okunan fonksiyonlari tutan arraylist e sahip sinif.
* </p>
*/
import java.util.ArrayList;

public class Classes {
	
	private String name;
	private ArrayList<Functions> functions = new ArrayList<Functions>();
	public Classes(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public ArrayList<Functions> getFunctions() {
		return functions;
	}
}
