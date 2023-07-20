
public class Koloni {
	private int populasyon;
	private int yemekStok;
	private int kazanma;
	private int kaybetme;
	private int sembol;
	private boolean is_alive;
	
	public Koloni(int populasyon) 
	{
		this.setPopulasyon(populasyon);
		this.yemekStok = (int) Math.pow(populasyon, 2);
		this.setKazanma(0);
		this.setKaybetme(0);
		this.setSembol(0);
		this.setIs_alive(true);
	}

	public void KoloniTurAtla()
	{
		populasyon += (populasyon * 1/5);
		yemekStok -= (populasyon * 2);
	}
	
	public void setPopulasyon(int populasyon) {
		this.populasyon = populasyon;
	}

	public void setYemekStok(int yemekStok) {
		this.yemekStok = yemekStok;
	}

	public void setKazanma(int kazanma) {
		this.kazanma = kazanma;
	}

	public void setKaybetme(int kaybetme) {
		this.kaybetme = kaybetme;
	}

	public void setSembol(int sembol) {
		this.sembol = sembol;
	}

	public void setIs_alive(boolean is_alive) {
		this.is_alive = is_alive;
	}

	public int getPopulasyon() {
		return populasyon;
	}

	public int getYemekStok() {
		return yemekStok;
	}

	public int getKazanma() {
		return kazanma;
	}

	public int getKaybetme() {
		return kaybetme;
	}

	public int getSembol() {
		return sembol;
	}

	public boolean isIs_alive() {
		return is_alive;
	}
	
}
