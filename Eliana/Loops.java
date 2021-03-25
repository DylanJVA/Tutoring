public class Loops {
    public static void main(String[] args) {
        

        int[] arrayX = {1,2,3,4,5};
        int[] arrayY = {6,7,8,9,10};
        int[] tempArray;
        tempArray = arrayX;
        arrayX = arrayY;
        arrayY = tempArray;
        for (int i = 0; i < 5; i++)
            System.out.print(arrayX[i] +", ");
        System.out.println();
        for (int i = 0; i < 5; i++)
            System.out.print(arrayY[i] +", ");
    }
    
}
