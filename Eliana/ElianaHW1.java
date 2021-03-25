import java.util.*;
public class ElianaHW1 {
    
    static int priority(char currentChar)
    {
        if (currentChar == '+' || currentChar == '-')
            return 1;
        else if (currentChar == '*' || currentChar == '/')
            return 2;
        else if (currentChar == '^')
            return 3;
        else   
            return -1;
    }
    static String infixToPostfix(String input)
    {
        String postfix = "";    
        Stack<Character> orderingStack = new Stack<>();
            
        for (int i = 0; i<input.length(); ++i)
        {
            char thisChar = input.charAt(i);  
            if (Character.isLetterOrDigit(thisChar))
                postfix += thisChar;  
            else if (thisChar == '(')
                orderingStack.push(thisChar);
            else if (thisChar == ')')
            {
                while (!orderingStack.isEmpty() && orderingStack.peek() != '(')
                    postfix += orderingStack.pop();
                orderingStack.pop();
            }
            else
            {
                while (!orderingStack.isEmpty() && priority(thisChar) <= priority(orderingStack.peek()))
                    postfix += orderingStack.pop();
                orderingStack.push(thisChar);
            }
        }
    
        while (!orderingStack.isEmpty()){
            if(orderingStack.peek() == '(')
                return "Invalid expression";
            postfix += orderingStack.pop();
            }
        return postfix;
    }

    static String postfixToInfix(String input) 
    {        
        Stack<String> resultStack = new Stack<String>(); 
        for (int i = 0; i < input.length(); i++) 
        { 
            // Push operands 
            if ((Character.toLowerCase(input.charAt(i)) >= 'a' && Character.toLowerCase(input.charAt(i)) <= 'z') || Character.isDigit(input.charAt(i)))
                resultStack.push(input.charAt(i) + ""); 
            else
            { 
                String firstOperator = resultStack.peek(); 
                resultStack.pop(); 
                String secondOperator = resultStack.peek(); 
                resultStack.pop(); 
                resultStack.push("(" + secondOperator + input.charAt(i) + firstOperator + ")"); 
            } 
        } 
        return resultStack.peek(); 
    }   
    
    public static void main(String[] args) 
    {
        Boolean leave = false;
        Scanner input = new Scanner(System.in);
        LinkedList<String> equations = new LinkedList<String>();
        int counter = 1;
        while(!leave)
        {
            System.out.println("\nPlease enter the number associated with one of the following options:");
            System.out.println("1. Infix to Postfix");
            System.out.println("2. Postfix to Infix");
            System.out.println("3. View recent translations");
            System.out.println("4. Exit");
            switch(Integer.parseInt(input.nextLine()))
            {
                case 1:
                    System.out.println("\nPlease enter the expression you wish to convert from infix to postfix");
                    String userinpitop = input.nextLine();
                    equations.add(counter+". "+userinpitop+" = "+infixToPostfix(userinpitop));
                    break;
                case 2:
                    System.out.println("\nPlease enter the expression you wish to convert from postfix to infix");
                    String userinpptoi = input.nextLine();
                    equations.add(counter+". "+userinpptoi+" = "+infixToPostfix(userinpptoi));
                    break;
                case 3:
                    for (int i = 0; i < equations.size(); i++)
                        System.out.println("\n"+equations.get(i));
                    break;
                case 4:
                    leave = true;
                    break;
            }
        }
        input.close();
    }
}
