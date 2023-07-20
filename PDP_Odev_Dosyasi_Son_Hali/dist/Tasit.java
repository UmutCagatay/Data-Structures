package orn;

public class Tasit {
    private Motor motor;
	private double hiz; 
    private double yol;
    private double depo; 
    
    public Tasit(double depo){
    	motor = new Motor();
        hiz=0;
        this.depo = depo;
        yol=0; //Baslangic yol sifir
    }
    public Tasit(String motorNo, double depo){
		/// Yeni motor nesnesi üretiliyor
    	motor = new Motor(motorNo);
        hiz=0;
        this.depo = depo;
        yol=0;
    }
	/**
	   Motor calistir.
	*/
    public void marsaBas() {
    	motor.calistir();
    }
	/**
	  Motor durdur. // --
	*/
    public void marsiKapat() {
    	motor.durdur();
    }
    public void sur(double zaman){
        yol = hiz * zaman;
        depo -= (yol/100)*ortalamaYakit();
    }
    public void hizAyarla(double hiz){
        this.hiz = hiz;
    }
    public double getHiz(){ // get hiz
        return hiz;
    }
    public double getYol(){ // get yol
        return yol;
    }
    public double getDepo(){ /* get depo */
        return depo;
    }
	/**
	 Ortalama yakit tuketimini hesaplar.
	*/
    public double ortalamaYakit(){
        if(hiz <= 100) return 7;
        else if(hiz <= 130) return 8;
        else if(hiz <= 150) return 9;
        else if(hiz <= 180) return 10;
        else if(hiz <= 200) return 12;
        else return 15; // diger her turlu 15 dondur.
    }
    public long menzil(){ // menzil fonksiyonu
		/*
		 Ortalama yakita gore
		 /*  Menzil hesabi
		*/
        return Math.round(100*(depo/ortalamaYakit()));
    }  
    @Override
    public boolean equals(Object obj) {
    	boolean kontrol =false;
    	if(obj != null && obj instanceof Tasit) {
    		kontrol = this.motor.getMotorNo().equals(((Tasit)obj).motor.getMotorNo());
    	}
    	return kontrol;
    }
	/**
	  String olarak nesne dondur.
	*/
    @Override
    public String toString() {
    	return "Tasit Motor No: "+motor.getMotorNo()+"\n"+motor;
    }
}