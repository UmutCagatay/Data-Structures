public abstract class Taktik {
	protected int pop;
	
	public Taktik() {
		this.pop = 0;
	}
	public void TaktikPopulasyonAl(int pop) {
		this.setPop(pop);
	}
	public abstract int Savas();
	
	public void setPop(int pop) {
		this.pop = pop;
	}
}
