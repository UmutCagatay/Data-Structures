/**
*
* @author Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
* @since 15.04.2023
* <p>
* Dosyadan okunan fonksiyonlarin atandigi sinif. Icerisinde fonksiyona ait yorumlari tutan arraylist'ler mevcut.
* </p>
*/
import java.util.ArrayList;

public class Functions {

	private String name;
	private ArrayList<String> singleCom = new ArrayList<String>();
	private ArrayList<String> multiCom = new ArrayList<String>();
	private ArrayList<String> javadocs = new ArrayList<String>();
	public Functions(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public ArrayList<String> getSingleCom() {
		return singleCom;
	}
	public ArrayList<String> getMultiCom() {
		return multiCom;
	}
	public ArrayList<String> getJavadocs() {
		return javadocs;
	}
	
}
