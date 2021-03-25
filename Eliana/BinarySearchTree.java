import java.util.Arrays;
import java.util.Scanner;
import java.lang.Math;

public class BinarySearchTree{
    
    static Node root;
    public static int realRoot;
    static Node arrayToTree (int array[], int lowest, int highest) {  
        if (lowest > highest)
            return null;
        Node node = new Node(array[(lowest+highest)/2]);
        
        node.left = arrayToTree(array,lowest,(lowest+highest)/2 - 1);
        node.right = arrayToTree(array,(lowest+highest)/2 +1, highest);
        
        return node;
    }

    public static void printTree(Node rootNode, int treeLevel) {
        if (rootNode == null)
            return;
        printTree(rootNode.right, treeLevel+1);
        if (treeLevel == 0)
            System.out.println(rootNode.value);
        else
        {
            for(int i = 0; i < treeLevel-1;i++)
                System.out.print("|\t");
            System.out.println("|-------"+rootNode.value);
        }
        printTree(rootNode.left, treeLevel+1);
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter favorite number");
        int numElements = input.nextInt();
        input.close();
        System.out.println();
        int randArray[] = new int[numElements];
        for (int i = 0; i < numElements; i++)
        {
            randArray[i]= (int)(Math.random()*1000+1);
        }
        Arrays.sort(randArray);
        System.out.print("Sorted array: ");
        for (int i = 0; i < numElements; i++)
        {
            System.out.print(randArray[i]+" ");
        }
        System.out.println("\nBinary Tree Representation:\n");
        root = arrayToTree(randArray,0,numElements-1);
        printTree(root, 0);
    }
}