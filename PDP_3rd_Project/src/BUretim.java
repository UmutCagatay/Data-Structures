
public class BUretim implements IUretim{

	private int pop = 0;
	@Override
	public void UretimPopulasyonAl(int pop) {
		
		this.setPop(pop);
	}

	@Override
	public int Uret() {
		
		return (int) Math.pow(pop, 1/3) % 10;
	}

	public void setPop(int pop) {
		this.pop = pop;
	}
}
