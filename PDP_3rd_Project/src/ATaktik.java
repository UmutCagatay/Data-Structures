
public class ATaktik extends Taktik{

	@Override
	public int Savas() {
		
		return (int) Math.pow(pop, 2) % 1000;
	}
	
}
