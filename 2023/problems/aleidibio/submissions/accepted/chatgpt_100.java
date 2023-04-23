import java.util.Scanner;

public class chatgpt_100 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Read in the input values
        int a = input.nextInt(); // Time to drive from Hannes to Arnar
        int b = input.nextInt(); // Time to drive from Arnar to cinema
        int c = input.nextInt(); // Scheduled start time of film

        // Calculate the latest possible minute for Hannes to start driving
        int latestMinute = c - (a + b);

        // Print the result
        System.out.println(latestMinute);
    }
}

