import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class einar_100{

	public static void main(String[] args) {
		try {
			BufferedReader input_hand = new BufferedReader(new InputStreamReader(System.in));

			String line1 = input_hand.readLine();
			String line2 = input_hand.readLine();

			System.out.println(line1+line2);

		} catch (IOException e){}
	}
}
