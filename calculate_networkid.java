import java.util.Scanner;

class Operation {
    int result1, result2, result3, result4;

    public void display(int subnetmask1, int subnetmask2, int subnetmask3, int subnetmask4, int a, int b, int c, int d) {
        result1 = a & subnetmask1;
        result2 = b & subnetmask2;
        result3 = c & subnetmask3;
        result4 = d & subnetmask4;
        System.out.println("\nThe Network ID of the given IP address: " + result1 + "." + result2 + "." + result3 + "." + result4);
    }
}

public class calculate_networkid {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        Operation obj2 = new Operation();

        System.out.print("\nEnter IP address: ");
        String ip = obj.nextLine();
        
        String octet[] = ip.split("\\.");

       
        if (octet.length != 4) {
            System.out.println("\nInvalid IP Address");
            return;
        }

        try {
            int a = Integer.parseInt(octet[0]);
            int b = Integer.parseInt(octet[1]);
            int c = Integer.parseInt(octet[2]);
            int d = Integer.parseInt(octet[3]);

           

            if (a > 255 || b > 255 || c > 255 || d > 255 || a < 0 || b < 0 || c < 0 || d < 0 ||octet.length != 4) {
                System.out.println("\nThis IP Address is not valid");
            } else {
                System.out.println("\nThis IP address is valid");

                 System.out.println("First octet: " + a);
                 System.out.println("Second octet: " + b);
                 System.out.println("Third octet: " + c);
                 System.out.println("Fourth octet: " + d);

                if (a >= 1 && a <= 126) {
                    System.out.println("\nThis IP address belongs to Class A");
                    obj2.display(255, 0, 0, 0, a, b, c, d);
                } else if (a >= 128 && a <= 191) {
                    System.out.println("\nThis IP address belongs to Class B");
                    obj2.display(255, 255, 0, 0, a, b, c, d);
                } else if (a >= 192 && a <= 223) {
                    System.out.println("\nThis IP address belongs to Class C");
                    obj2.display(255, 255, 255, 0, a, b, c, d);
                } else if (a >= 224 && a <= 239) {
                    System.out.println("\nThis IP address belongs to Class D");
                    System.out.println("\nClass D is used for multicasting, so network ID calculation is not posible");
                } else if (a >= 240 && a <= 255) {
                    System.out.println("\nThis IP address belongs to Class E");
                    System.out.println("\nClass E is reserved for future applications, so network ID calculation is not posible");
                }
            }
        } catch (NumberFormatException e) {
            System.out.println("\nInvalid IP Address.");
        }

}
}