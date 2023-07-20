
public class BTaktik extends Taktik{

	@Override
	public int Savas() {
		
		return (int) Math.pow(pop, 3) % 1000;
	}

}
