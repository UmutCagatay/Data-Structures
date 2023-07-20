/**
*
* @author Umut Can Cagatay - umut.cagatay@ogr.sakarya.edu.tr
* @since 15.04.2023
* <p>
* Main metodunun oldugu sinif.
* </p>
*/
import java.io.*;

public class main {

	public static void main(String[] args) throws IOException{
		
		FileOperations fileOp = new FileOperations(args[0]);
		
		fileOp.detectFunctions();
		fileOp.detectComments();
		fileOp.printScreen();
		fileOp.writeToFile();
	}
}
