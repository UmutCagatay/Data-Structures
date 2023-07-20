/**
*
* @author Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
* @since 15.04.2023
* <p>
* Dosyanin okunup sinif, fonksiyon ve yorumlarin belirlendigi, verilerin ekrana yazdirilmasi ve verilerin dosyalara islenmesini saglayan fonksiyonlari bulunduran sinif.
* </p>
*/
import java.io.*;
import java.util.ArrayList;

public class FileOperations {
	
	File rfile;
	public FileOperations(String file)
	{
		rfile = new File(file);
	}
	Regex regex = new Regex();
	
	ArrayList<Classes> classes = new ArrayList<Classes>();
	
	int class_counter = -1;
	
	FileReader freader;
	String line;
	BufferedReader breader;
	
	public void detectFunctions() throws IOException{ //Dosyada ki sinif ve fonksiyonlari sisteme aktarir. Bu islemi yaparken sadece sinif ve fonksiyonlarin isimlerini secer.
		freader = new FileReader(rfile);
		breader = new BufferedReader(freader);
		while((line = breader.readLine()) != null) {
			if (line.matches(regex.getClass_pattern())) {
				line = line.replaceAll(regex.getClassFrontPart_pattern(), "");
				line = line.replaceAll(regex.getClassEndPart_pattern(), "");
				classes.add(new Classes(line));
				class_counter++;
			}
			if (line.matches(regex.getFunction_pattern())) {
				line = line.replaceAll(regex.getFunctionFrontPart_pattern(), "");
				line = line.replaceAll(regex.getFunctionEndPart_pattern(), "");
				classes.get(class_counter).getFunctions().add(new Functions(line));
			}
		}
		breader.close();
	}
	
	public void detectComments() throws IOException{ //Dosyada ki yorumlari sistemdeki ait olmalari gereken sinif ve fonksiyonlara atar. Bu islemi yaparken yorumlari filtreler ve cevresinde yazilan yorum olmayan kisimlari siler. Boylece sadece yorumlari sisteme almis olur.
		freader = new FileReader(rfile);
		breader = new BufferedReader(freader);
		class_counter = -1;
		int function_counter = 0;
		int bracket_counter = 0;
		while((line = breader.readLine()) != null) {
			if (line.matches(regex.getClass_pattern())) {
				class_counter++;
				function_counter = 0;
			}
			if (line.matches(regex.getJavadoc_pattern())) {
				String gecjavadoc = new String("");
				while(!line.matches(regex.getClosing_pattern())) {
					gecjavadoc = gecjavadoc.concat(line);
					gecjavadoc = gecjavadoc.concat("\n");
					line = breader.readLine();
				}
				line = line.replaceAll(regex.getJavadocFrontPart_pattern(), "");
				line = line.replaceAll(regex.getClosingEndPart_pattern(), "");
				gecjavadoc = gecjavadoc.concat(line);
				classes.get(class_counter).getFunctions().get(function_counter).getJavadocs().add(gecjavadoc);
			}
			if (line.matches(regex.getMulti_pattern())) {
				String gecmulti = new String("");
				while(!line.matches(regex.getClosing_pattern())) {
					gecmulti = gecmulti.concat(line);
					gecmulti = gecmulti.concat("\n");
					line = breader.readLine();
				}
				line = line.replaceAll(regex.getMultiFrontPart_pattern(), "");
				line = line.replaceAll(regex.getClosingEndPart_pattern(), "");
				gecmulti = gecmulti.concat(line);
				classes.get(class_counter).getFunctions().get(function_counter).getMultiCom().add(gecmulti);
			}
			if (line.matches(regex.getSingle_pattern())) {
				if (!(line.matches(regex.getSingleCheck_pattern()))) {
					line = line.replaceAll(regex.getSingleFrontPart_pattern(), "");
				}
				classes.get(class_counter).getFunctions().get(function_counter).getSingleCom().add(line);	
			}
			if (!line.matches(regex.getClass_pattern()) && !line.matches(regex.getFunction_pattern()) && line.matches(regex.getBegin_pattern())) { //Eger { karakteri okunan satir bir class veya fonksiyon degilse parantez sayacini 1 arttirir.
				bracket_counter++;
			}
			else if (line.matches(regex.getEnd_pattern())) { //Eger parantez sayaci 0 ise sonraki fonksiyona gecer. Parantez sayaci 0 degilse 1 azaltir.
				if (bracket_counter == 0) {
					function_counter++;
				}
				else {
					bracket_counter--;
				}
			}
		}
		breader.close();
	}
	
	public void printScreen() throws IOException{ //Sistemdeki verileri ekrana yazdirir.
		for (int i = 0; i < classes.size(); i++) {
			System.out.println("Sinif: " + classes.get(i).getName());
			for (int j = 0; j < classes.get(i).getFunctions().size(); j++) {
				System.out.println("\tFonksiyon: " + classes.get(i).getFunctions().get(j).getName());
				System.out.println("\t\tTek Satir Yorum Sayisi:\t  " + classes.get(i).getFunctions().get(j).getSingleCom().size());
				System.out.println("\t\tCok Satirli Yorum Sayisi: " + classes.get(i).getFunctions().get(j).getMultiCom().size());
				System.out.println("\t\tJavadoc Yorum Sayisi:\t  " + classes.get(i).getFunctions().get(j).getJavadocs().size());
				System.out.println("-------------------------------------------");
			}
		}
	}
	
	public void writeToFile() throws IOException{ //Sistemdeki verileri turune gore dosyalara aktarir.
		File wfile = new File("javadoc.txt");
		if (!wfile.exists()) {
			wfile.createNewFile();
		}
		FileWriter fwriter = new FileWriter(wfile);
		BufferedWriter bwriter = new BufferedWriter(fwriter);
		
		for (int i = 0; i < classes.size(); i++) {
			bwriter.write("  Sinif: " + classes.get(i).getName());
			bwriter.newLine();
			bwriter.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			bwriter.newLine();
			for (int j = 0; j < classes.get(i).getFunctions().size(); j++) {
				bwriter.write("Fonksiyon: " + classes.get(i).getFunctions().get(j).getName() + "\n\n");
				for (String text : classes.get(i).getFunctions().get(j).getJavadocs()) {
					bwriter.write(text);
					bwriter.newLine();
				}
				bwriter.newLine();
				bwriter.write("-------------------------------------------");
				bwriter.newLine();
			}
			bwriter.newLine();
		}
		bwriter.close();
		
		wfile = new File("coksatir.txt");
		if (!wfile.exists()) {
			wfile.createNewFile();
		}
		fwriter = new FileWriter(wfile);
		bwriter = new BufferedWriter(fwriter);
		
		for (int i = 0; i < classes.size(); i++) {
			bwriter.write("  Sinif: " + classes.get(i).getName());
			bwriter.newLine();
			bwriter.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			bwriter.newLine();
			for (int j = 0; j < classes.get(i).getFunctions().size(); j++) {
				bwriter.write("Fonksiyon: " + classes.get(i).getFunctions().get(j).getName() + "\n\n");
				for (String text : classes.get(i).getFunctions().get(j).getMultiCom()) {
					bwriter.write(text);
					bwriter.newLine();
				}
				bwriter.newLine();
				bwriter.write("-------------------------------------------");
				bwriter.newLine();
			}
			bwriter.newLine();
		}
		bwriter.close();
		
		wfile = new File("teksatir.txt");
		if (!wfile.exists()) {
			wfile.createNewFile();
		}
		fwriter = new FileWriter(wfile);
		bwriter = new BufferedWriter(fwriter);
		
		for (int i = 0; i < classes.size(); i++) {
			bwriter.write("  Sinif: " + classes.get(i).getName());
			bwriter.newLine();
			bwriter.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			bwriter.newLine();
			for (int j = 0; j < classes.get(i).getFunctions().size(); j++) {
				bwriter.write("Fonksiyon: " + classes.get(i).getFunctions().get(j).getName() + "\n\n");
				for (String text : classes.get(i).getFunctions().get(j).getSingleCom()) {
					bwriter.write(text);
					bwriter.newLine();
				}
				bwriter.newLine();
				bwriter.write("-------------------------------------------");
				bwriter.newLine();
			}
			bwriter.newLine();
		}
		bwriter.close();
	}
}
