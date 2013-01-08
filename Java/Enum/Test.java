public enum Test {
    MERCURY (3, 2),
    VENUS   (4, 6);
    private final int mass;
    private final int radius;
    Test(int _mass,int _radius) {
        this.mass  = _mass;
        this.radius = _radius;
    }
    String compute (int _val){
        int res = this.mass * _val;
        return Integer.toString(res);
    }
    public static void main(String[] args) {
        for (Test p : Test.values()) {System.out.printf(p.compute(5));}
    }
}
