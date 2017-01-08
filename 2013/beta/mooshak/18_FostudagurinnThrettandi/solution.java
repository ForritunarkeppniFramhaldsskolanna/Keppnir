import java.util.*;
import java.math.*;
import java.io.*;

public class solution
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out, false);

		int ts = in.nextInt();

		for (int t = 0; t < ts; t++)
		{
			int y = in.nextInt(),
				cnt = 0;

			for (int m = 0; m < 12; m++)
			{
				GregorianCalendar gc = new GregorianCalendar(y, m, 13);
				if (gc.get(Calendar.DAY_OF_WEEK) == Calendar.FRIDAY)
				{
					cnt++;
				}
			}

			out.println(cnt);
		}

		out.flush();
	}
}