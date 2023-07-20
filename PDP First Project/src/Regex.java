/**
*
* @author Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
* @since 15.04.2023
* <p>
* Belirli karakter dizilerinin regex tanimlarini tutan ve erisim saglayan sinif.
* </p>
*/
public class Regex {	//Asagidaki yorum satirlari patternlerin aradiklarini acikliyor.
	
	private String class_pattern; //Sinif
	private String function_pattern; //Fonksiyon
	private String single_pattern; //Tekli yorum
	private String multi_pattern; //Coklu Yorum
	private String javadoc_pattern; //Javadoc
	private String closing_pattern; //Coklu Yorum ve Javadoc kapatmayi saglayan */ ariyor.
	private String begin_pattern; // { arar.
	private String end_pattern; // } arar.
	
	private String classFrontPart_pattern; //Bulunan sinifin adindan onceki kisimi silmek icin pattern.
	private String functionFrontPart_pattern; //Bulunan fonksiyonun adindan onceki kisimi silmek icin pattern.
	private String classEndPart_pattern; //Bulunan sinifin adindan sonraki kisimi silmek icin pattern.
	private String functionEndPart_pattern; //Bulunan sinifin adindan sonraki kisimi silmek icin pattern.
	
	private String multiFrontPart_pattern; //Bulunan coklu yorumdan onceki kisimi silmek icin pattern.
	private String javadocFrontPart_pattern; //Bulunan javadoc'dan onceki kisimi silmek icin pattern.
	
	private String singleFrontPart_pattern; //Bulunan tekli yorumundan onceki kisimi silmek icin pattern.
	private String singleCheck_pattern; //Tekli satilar bir satirda birden fazla kullanilabilir //asdf// gibi. Bu yazim ile cikan hatalari onlemek icin bir kontrol pattern.
	private String closingEndPart_pattern; // */ karakter dizisinden sonraki kisimi silmek icin pattern.
	
	public Regex() {

		this.class_pattern = "(public)?\\sclass\\s\\w+(\\s*\\{?)?";
		this.function_pattern = "(public|private|protected)\\s((void|String|int|float|double|char)\\s)?\\w+\\((.+)?\\)(\\s*\\{?)?";
		this.single_pattern = "(.+)?(\\/\\/).+";
		this.multi_pattern = "(.+)?(\\/\\*)([^\\*](.+)?|[^\\*]\\s*)?";
		this.javadoc_pattern = "(.+)?(\\/\\*\\*)([^\\*](.+)?|[^\\*]\\s*)?";
		this.closing_pattern = "(.+)?(\\*\\/)(.+)?";
		
		this.begin_pattern = ".*\\{.*";
		this.end_pattern = ".*\\}.*";
		
		this.classFrontPart_pattern = "(public)?\\sclass\\s";
		this.functionFrontPart_pattern = "(public|private|protected)\\s((void|String|int|float|double|char)\\s)?";
		this.classEndPart_pattern = "(\\s*\\{?)?";
		this.functionEndPart_pattern = "\\((.+)?\\)(\\s*\\{?)?";
		
		this.singleFrontPart_pattern = ".+(?=\\/\\/)";
		this.singleCheck_pattern = "\\/\\/.+\\/\\/";
		this.closingEndPart_pattern = "(?<=.*\\*\\/)(.+)?";
		this.multiFrontPart_pattern = ".+(?=(\\/\\*)([^\\*](.+)?|[^\\*]\\s*)?)";
		this.javadocFrontPart_pattern = ".+(?=(\\/\\*\\*)([^\\*](.+)?|[^\\*]\\s*)?)";
	}
	
	public String getBegin_pattern() {
		return begin_pattern;
	}

	public String getMultiFrontPart_pattern() {
		return multiFrontPart_pattern;
	}

	public String getJavadocFrontPart_pattern() {
		return javadocFrontPart_pattern;
	}

	public String getSingleCheck_pattern() {
		return singleCheck_pattern;
	}
		
	public String getSingleFrontPart_pattern() {
		return singleFrontPart_pattern;
	}

	public String getClosingEndPart_pattern() {
		return closingEndPart_pattern;
	}

	public String getClass_pattern() {
		return class_pattern;
	}

	public String getFunction_pattern() {
		return function_pattern;
	}

	public String getSingle_pattern() {
		return single_pattern;
	}

	public String getMulti_pattern() {
		return multi_pattern;
	}

	public String getJavadoc_pattern() {
		return javadoc_pattern;
	}

	public String getClosing_pattern() {
		return closing_pattern;
	}
	
	public String getEnd_pattern() {
		return end_pattern;
	}

	public String getClassFrontPart_pattern() {
		return classFrontPart_pattern;
	}

	public String getFunctionFrontPart_pattern() {
		return functionFrontPart_pattern;
	}

	public String getClassEndPart_pattern() {
		return classEndPart_pattern;
	}

	public String getFunctionEndPart_pattern() {
		return functionEndPart_pattern;
	}
	
}
