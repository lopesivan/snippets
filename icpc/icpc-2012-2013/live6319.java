import java.util.*;
import java.io.*;

class Main {
	
	public static void main(String[] args) throws Exception {
		
		int TC, TCi;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer("");
		String line;
		
		line = reader.readLine();
		TC = Integer.parseInt(line);
			
		for (TCi = 0; TCi < TC; ++TCi) {
			StringBuilder s = new StringBuilder(reader.readLine());
			
			while(true) {
				tokenizer = new StringTokenizer(reader.readLine());
				int a, b;
				String ins;
				String op = tokenizer.nextToken();
				
				if ( op.equals("I") ) {
					ins = tokenizer.nextToken();
					a = Integer.parseInt(tokenizer.nextToken());
					s.insert(a, ins);
				}
				
				else if (op.equals("P")) {
					a = Integer.parseInt(tokenizer.nextToken());
					b = Integer.parseInt(tokenizer.nextToken());
					
					if (b >= s.length())
					    b = s.length() - 1;
										
					System.out.println(s.substring(a, b + 1));
				}
				else {
					break;
				}
			}
			
		}
		System.exit(0);
	}
}
