import java.lang.String;
import java.util.Scanner;

public class main
{
        public float Sum(float firstValue, float secondValue)
        {
                float result = firstValue + secondValue;

                return result;
        }

        public static float Sub(float firstValue, float secondValue)
        {
                float result = firstValue - secondValue;

                return result;
        }

        public static float Mult(float firstValue, float secondValue)
        {
                float result = firstValue * secondValue;

                return result;
        }

        public static float Div(float firstValue, float secondValue)
        {
                float result = firstValue / secondValue;

                return result;
        }

        public static float Mod(float firstValue, float secondValue)
        {
                float result = firstValue % secondValue;

                return result;
        }

        public void main()
        {
                Scanner num = new Scanner(System.in);

                float firstValue, secondValue, result = 0f;
                String action;

                System.out.println("Input first value:");
                firstValue = num.nextInt();

                System.out.println("Input second value:");
                secondValue = num.nextInt();

                System.out.println("Input action: ");
                action = num.nextLine();

                switch(action)
                {
                        case "+":
                        {
                                result = Sum(firstValue, secondValue);

                                break;
                        }

                        case "-":
                        {
                                result = Sub(firstValue, secondValue);;

                                break;
                        }

                        case "*":
                        {
                                result = Mult(firstValue, secondValue);

                                break;
                        }

                        case "/":
                        {
                                result = Div(firstValue, secondValue);

                                break;
                        }

                        case "%":
                        {
                                result = Mod(firstValue, secondValue);

                                break;
                        }

                        default:
                        {
                                System.out.println("Error! No such action;");

                                break;
                        }
                }
        }
}
