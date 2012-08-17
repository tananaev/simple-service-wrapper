class TestApp {
    public static void main(String[] args) {
        try {
            while (true) {
                System.out.print(".");
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.print("!");
        }
    }
}
